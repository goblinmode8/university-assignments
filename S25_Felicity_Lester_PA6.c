// NAME : Felicity Lester
// CS 4350 – 251 - Unix Systems Programming
// Assignment Number : 7
// Due Date: 4 / 23 / 2025
//
//
// DESCRIPTION:
// This program simulates four CPU scheduling algorithms using threads:
// First Come, First Served (FCFS), Shortest Job First (SJF),
// Priority Queue (PQ), and Round Robin (RR with Time Quantum = 100ms).
// It processes a static list of 10 processes, each with an ID, duration, and priority,
// and calculates the total completion time for each scheduling strategy.
// Threads are used to simulate each algorithm in sequence,
// and synchronization techniques (e.g., mutexes) are used where necessary.
// The results are printed in the format required by the assignment.



#include <stdio.h>
#include <stdlib.h>  // For rand(), srand()
#include <time.h>    // For seeding random numbers
#include <pthread.h>


// Global arrays for process information
int processID[10] = {5, 11, 238, 254, 330, 637, 1042, 1163, 1364, 1404};
int duration[10] = {100, 20, 80, 20, 140, 220, 360, 120, 170, 110};
int priority[10] = {1, 10, 3, 5, 7, 2, 8, 4, 9, 6};


// Global variables
int totalDurationFCFS = 0;
int totalDurationSJFS = 0;
int totalDurationPQ = 0;
int totalDurationRR = 0;
pthread_mutex_t lock;
 

// Function: fcfs
// --------------------
// Simulates First Come, First Served (FCFS) scheduling.
// Prints all 10 processes in their original order and calculates
// the total duration for all processes.
//
void* fcfs(void* arg) {
    pthread_mutex_lock(&lock);

    printf("First Come, First Served Simulation\n");
    printf("\nProcess ID  Duration  Priority\n");
    printf("----------------------------------------\n");

    for (int i = 0; i < 10; i++) {
	printf("%-10d %-10d %-10d\n", processID[i], duration[i], priority[i]);
        totalDurationFCFS += duration[i];
    }

    printf("\n\nTotal Duration : %d\n\n", totalDurationFCFS);
    
    pthread_mutex_unlock(&lock);
    pthread_exit(NULL);
}


// Function: sjfs
// --------------------
// Simulates Shortest Job First (SJF) scheduling.
// Sorts the processes by ascending duration, then prints them.
// Calculates the total duration based on the sorted order.
//
void* sjfs(void* arg) {
    pthread_mutex_lock(&lock);

    printf("\nShortest Job First Simulation\n");
    printf("\nProcess ID  Duration  Priority\n");
    printf("----------------------------------------\n");

    // Create a local copy of the index array to sort durations
    int indices[10];
    for (int i = 0; i < 10; i++) {
        indices[i] = i;
    }

    // Selection sort by duration
    for (int i = 0; i < 9; i++) {
        for (int j = i + 1; j < 10; j++) {
            if (duration[indices[i]] > duration[indices[j]]) {
                int temp = indices[i];
                indices[i] = indices[j];
                indices[j] = temp;
            }
        }
    }

    // Print sorted processes
    for (int i = 0; i < 10; i++) {
        int idx = indices[i];
        printf("%-10d %-10d %-10d\n", processID[idx], duration[idx], priority[idx]);
        totalDurationSJFS += duration[idx];
    }

    printf("\n\nTotal Duration : %d\n\n\n", totalDurationSJFS);

    pthread_mutex_unlock(&lock);
    pthread_exit(NULL);
}


// Function: pq
// --------------------
// Simulates Priority Queue scheduling.
// Sorts the processes by descending priority (higher number = higher priority),
// then prints them and calculates the total duration.
//
void* pq(void* arg) {
    pthread_mutex_lock(&lock);

    printf("Priority Queue Simulation\n\n");
    printf("Process ID  Duration  Priority\n");
    printf("----------------------------------------\n");

    int indices[10];
    for (int i = 0; i < 10; i++) {
        indices[i] = i;
    }

    // Sort by descending priority (higher = higher priority)
    for (int i = 0; i < 9; i++) {
        for (int j = i + 1; j < 10; j++) {
            if (priority[indices[i]] < priority[indices[j]]) {
                int temp = indices[i];
                indices[i] = indices[j];
                indices[j] = temp;
            }
        }
    }

    for (int i = 0; i < 10; i++) {
        int idx = indices[i];
        printf("%-10d %-10d %-10d\n", processID[idx], duration[idx], priority[idx]);
        totalDurationPQ += duration[idx];
    }

    printf("\nTotal Duration : %d\n\n", totalDurationPQ);

    pthread_mutex_unlock(&lock);
    pthread_exit(NULL);
}


// Function: rr
// --------------------
// Simulates Round Robin scheduling with a time quantum of 100 ms.
// Each process runs in time slices, cycling through until all are finished.
// Prints each slice and calculates the total duration.
//
void* rr(void* arg) {
    pthread_mutex_lock(&lock);

    printf("\nRound Robin Simulation with Time Quantum = 100 ms\n");
    printf("\nProcess ID  Duration  Priority\n");
    printf("----------------------------------------\n");

    int remaining[10];
    for (int i = 0; i < 10; i++) {
        remaining[i] = duration[i];
    }

    int allDone = 0;
    while (!allDone) {
        allDone = 1;
        for (int i = 0; i < 10; i++) {
            if (remaining[i] > 0) {
                allDone = 0;

                int slice = remaining[i] >= 100 ? 100 : remaining[i];
                printf("%-10d %-10d %-10d\n", processID[i], slice, priority[i]);

                remaining[i] -= slice;
                totalDurationRR += slice;
            }
        }
    }

    printf("\nTotal Duration : %d\n\n", totalDurationRR);

    pthread_mutex_unlock(&lock);
    pthread_exit(NULL);
}


int main() {

pthread_mutex_init(&lock, NULL);

pthread_t t1;
pthread_t t2;
pthread_t t3;
pthread_t t4;

    printf("Welcome to Felicity Lester’s Thread Program\n\n");

    printf("This program will simulate the CPU scheduling Algorithms in the following order:\n");
    printf("    • First Come, First Served\n");
    printf("    • Shortest Job First\n");
    printf("    • Priority Queue\n");
    printf("    • Round Robin\n\n\n");


    pthread_create(&t1, NULL, fcfs, NULL);
    pthread_join(t1, NULL);

    pthread_create(&t2, NULL, sjfs, NULL);
    pthread_join(t2, NULL);
    
    pthread_create(&t3, NULL, pq, NULL);
    pthread_join(t3, NULL);

    pthread_create(&t4, NULL, rr, NULL);
    pthread_join(t4, NULL);


    pthread_mutex_destroy(&lock);    


    printf("Programmed by Felicity Lester :)\n");
    printf("4 - 23 - 2025\n");


    return 0;
}
