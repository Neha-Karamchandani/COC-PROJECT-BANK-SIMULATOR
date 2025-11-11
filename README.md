# COC-PROJECT-BANK-SIMULATOR
Short Description
This is a C program that simulates the operation of a bank queue where a customer arrives randomly,using "Poisson Distribution" are served by one or more tellers.
Real world issue it represents :
customers arrives randomly and no teller is free then the customers have to wait in queue ,this project is the  computer simulation of this pocess.
Concepts used:
OF C -
1.Structures (struct) - to represent customers and queues
2.Pointers - to link customers dynamically
3.Dynamic Memory (malloc()) - to create new customers as they arrives
4.Random Numbers (rand(),srand(time(NULL))) - for simulating arrivals and service times
5.Loops - to simulate time minute by minute
6.If else - checks teller availability,queue status and hanndles arrival and departure
OF Maths -
1.Poisson Distribution - to model random arrival interval
2.Central tendencies - Mean,Median,Mode
3.standard Deviation

HOW TO COMPILE :
gcc coc-bank-simulator-poisson.c -o bankqueuesimulator
Open the terminal and type this 

HOW TO RUN :
After compiling the program run the program by typing
./bankqueuesimulator
Now you will be prompted to enter inputs;
Enter average arrivals per minute (lambda): 1
Enter number of tellers: 3

The output You will receive

--------------------------
Simulation Report
--------------------------
Lambda (arrivals/min): 1.00
Tellers: 3
Total customers served: 473
Mean wait time: 1.69 minutes
Median wait time: 1.00 minutes
Mode wait time: 0 minutes
Standard deviation: 2.24
Maximum wait time: 11 minutes



