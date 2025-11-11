# 🏦 Bank Queue (Poisson) Simulator

## 📝 Short Description
This is a C program that simulates the operation of a bank queue where a customer arrives randomly, using "Poisson Distribution", and is served by one or more tellers.

---

## 🌍 Real world issue it represents
Customers arrive randomly and if no teller is free, then the customers have to wait in a queue.  
This project is the computer simulation of this process.

---

## 🧠 Concepts used

### 🔹 Of C
1. Structures (struct) - to represent customers and queues  
2. Pointers - to link customers dynamically  
3. Dynamic Memory (malloc()) - to create new customers as they arrive  
4. Random Numbers (rand(), srand(time(NULL))) - for simulating arrivals and service times  
5. Loops - to simulate time minute by minute  
6. If-Else - checks teller availability, queue status and handles arrival and departure  

---

### 🔹 Of Mathematics
1. Poisson Distribution - to model random arrival interval  
2. Central Tendencies - Mean, Median, Mode  
3. Standard Deviation  

---

## ⚙️ HOW TO COMPILE
gcc coc-bank-simulator-poisson.c -o bankqueuesimulator  
Open the terminal and type this command.

---

## ▶️ HOW TO RUN
After compiling the program, run the program by typing:  
./bankqueuesimulator  

---

### 🧩 You will then be prompted to enter inputs
Enter average arrivals per minute (lambda): 1  
Enter number of tellers: 3  

---

### 📊 The output you will receive
Simulation Report  
Lambda (arrivals/min): 1.00  
Tellers: 3  
Total customers served: 473  
Mean wait time: 1.69 minutes  
Median wait time: 1.00 minutes  
Mode wait time: 0 minutes  
Standard deviation: 2.24  
Maximum wait time: 11 minutes  

---

## ✨ Summary
This simulation represents how customers arrive and wait in a bank queue, applying both C programming and mathematical statistics.  
It helps in understanding how arrival rate (λ), number of tellers, and service time affect:  
- Average waiting time  
- Total customers served  
- Queue performance  

This project demonstrates the integration of programming logic with probability and queueing theory concepts effectively.
 





