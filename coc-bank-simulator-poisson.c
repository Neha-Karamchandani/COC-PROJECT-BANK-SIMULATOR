//Bank Queue(poisson) simulator
//it simulates bank queue using random arrivals by using poisson distribution
//also calculates central tendencies and standard deviation and max time for customers
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

//Structure for  each customer in queue 
struct Customer {
    int arrival_time;       // When they entered the queue
    int service_time;       // How long service takes
    int start_service;      // When service actually starts
    struct Customer *next;  // Pointer to next customer
};

//Queue structure using linked list 
struct Queue {
    struct Customer *front;
    struct Customer *rear;
    int size;
};
//initializing queue
void initQueue(struct Queue *q) {
    q->front = q->rear = NULL;
    q->size = 0;
}

//Adding a new customer to the queue 
void enqueue(struct Queue *q, struct Customer *c) {
    if (q->rear == NULL) {
        q->front = q->rear = c;
    } else {
        q->rear->next = c;
        q->rear = c;
    }
    q->size++;
}

// Removing customer from queue 
struct Customer* dequeue(struct Queue *q) {
    if (q->front == NULL)
        return NULL;
    struct Customer *temp = q->front;
    q->front = q->front->next;
    if (q->front == NULL)
        q->rear = NULL;
    q->size--;
    return temp;
}

//Checking if queue empty 
int isEmpty(struct Queue *q) {
    return (q->front == NULL);
}

//Function to create a new customer 
struct Customer* newCustomer(int arrival, int service) {
    struct Customer *c = (struct Customer*)malloc(sizeof(struct Customer));
    c->arrival_time = arrival;
    c->service_time = service;
    c->start_service = -1;
    c->next = NULL;
    return c;
}

//Generating random arrivals using Poisson distribution
int poissonRandom(double lambda) {
    double L = exp(-lambda);
    int k = 0;
    double p = 1.0;
    do {
        k++;
        double u = (double)rand() / RAND_MAX;
        p *= u;
    } while (p > L);
    return k - 1;
}

//Basic statistics functions and standard deviation and maximum time 
double mean(int arr[], int n) {
    double sum = 0;
    for (int i = 0; i < n; i++) sum += arr[i];
    return sum / n;
}

void sort(int arr[], int n) {
    for (int i = 0; i < n-1; i++)
        for (int j = 0; j < n-i-1; j++)
            if (arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
}

double stddev(int arr[], int n, double meanVal) {
    double sum = 0;
    for (int i = 0; i < n; i++) {
        double diff = arr[i] - meanVal;
        sum += diff * diff;
    }
    return sqrt(sum / n);
}

int mode(int arr[], int n) {
    int maxCount = 0, modeVal = arr[0];
    int count = 1;
    for (int i = 1; i < n; i++) {
        if (arr[i] == arr[i-1]) {
            count++;
        } else {
            if (count > maxCount) {
                maxCount = count;
                modeVal = arr[i-1];
            }
            count = 1;
        }
    }
    if (count > maxCount) modeVal = arr[n-1];
    return modeVal;
}

// beginning of final simulator
int main() {
    
    double lambda;
    int tellers, sim_time;
    
    srand(time(NULL));
    struct Queue q;
    initQueue(&q);

    printf("Enter average arrivals per minute (lambda): ");
    scanf("%lf", &lambda);

    printf("Enter number of tellers: ");
    scanf("%d", &tellers);

    int teller_free[5] = {0}; // supports up to 5 tellers
    
    int waits[10000]; // store waiting times
    int total_waits = 0;

    int total_minutes = 480; //  for 8 hours i.e 480 minutes

    // Simulating each minute by for loop
    for (int minute = 0; minute < total_minutes; minute++) {

        // Step 1- Generating a random arrivals this minute
        int arrivals = poissonRandom(lambda);
        for (int i = 0; i < arrivals; i++) {
            int service_time = (rand() % 2) + 2; // 2 or 3 mins
            struct Customer *c = newCustomer(minute, service_time);
            enqueue(&q, c);
        }

        // Step 2-Assigning free tellers to waiting customers
        for (int t = 0; t < tellers; t++) {
            if (teller_free[t] <= minute && !isEmpty(&q)) {
                struct Customer *c = dequeue(&q);
                c->start_service = minute;
                int wait = c->start_service - c->arrival_time;
                waits[total_waits++] = wait;
                teller_free[t] = minute + c->service_time;
                free(c);
            }
        }
    }

    // After 480 minutes, finish remaining queue
    int minute = total_minutes;
    while (!isEmpty(&q)) {
        for (int t = 0; t < tellers; t++) {
            if (teller_free[t] <= minute && !isEmpty(&q)) {
                struct Customer *c = dequeue(&q);
                c->start_service = minute;
                int wait = c->start_service - c->arrival_time;
                waits[total_waits++] = wait;
                teller_free[t] = minute + c->service_time;
                free(c);
            }
        }
        minute++;
    }

    // Step 3- Calculating statistics functions
    if (total_waits == 0) {
        printf("\nNo customers served.\n");
        return 0;
    }

    sort(waits, total_waits);
    double meanVal = mean(waits, total_waits);
    double medianVal = (total_waits % 2 == 0) 
                        ? (waits[total_waits/2 - 1] + waits[total_waits/2]) / 2.0
                        : waits[total_waits/2];
    int modeVal = mode(waits, total_waits);
    double stdVal = stddev(waits, total_waits, meanVal);
    int maxVal = waits[total_waits - 1];

    // Step 4- Displaying the results
    printf("\n--------------------------\n");
    printf("Simulation Report\n");
    printf("--------------------------\n");
    printf("Lambda (arrivals/min): %.2f\n", lambda);
    printf("Tellers: %d\n", tellers);
    printf("Total customers served: %d\n", total_waits);
    printf("Mean wait time: %.2f minutes\n", meanVal);
    printf("Median wait time: %.2f minutes\n", medianVal);
    printf("Mode wait time: %d minutes\n", modeVal);
    printf("Standard deviation: %.2f\n", stdVal);
    printf("Maximum wait time: %d minutes\n", maxVal);
    printf("--------------------------\n");

    return 0;
}



