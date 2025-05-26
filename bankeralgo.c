/**
 * Deadlock Detection Algorithm Implementation in C
 *
 * This program implements the banker's algorithm to detect deadlocks
 * in a system with multiple processes and resources.
 */

#include <stdio.h>

int max[100][100];     // Maximum resources each process can request
int alloc[100][100];   // Resources currently allocated to each process
int need[100][100];    // Resources still needed by each process
int avail[100];        // Available resources in the system
int work[100];         // Working copy of available resources
int n, r;              // Number of processes and resources

void input();
void show();
void detect_deadlock();

int main() {
    printf("********** Deadlock Detection Algorithm ************\n");
    input();
    show();
    detect_deadlock();
    return 0;
}

void input() {
    int i, j;
    printf("Enter the number of Processes: ");
    scanf("%d", &n);
    printf("Enter the number of resource types: ");
    scanf("%d", &r);
    
    printf("\nEnter the Max Matrix:\n");
    for (i = 0; i < n; i++) {
        printf("For Process P%d: ", i+1);
        for (j = 0; j < r; j++) {
            scanf("%d", &max[i][j]);
        }
    }
    
    printf("\nEnter the Allocation Matrix:\n");
    for (i = 0; i < n; i++) {
        printf("For Process P%d: ", i+1);
        for (j = 0; j < r; j++) {
            scanf("%d", &alloc[i][j]);
        }
    }
    
    printf("\nEnter the Available Resource Vector:\n");
    for (j = 0; j < r; j++) {
        printf("Resource %d: ", j+1);
        scanf("%d", &avail[j]);
    }
    
    // Calculate need matrix
    for (i = 0; i < n; i++) {
        for (j = 0; j < r; j++) {
            need[i][j] = max[i][j] - alloc[i][j];
        }
    }
}

void show() {
    int i, j;
    
    printf("\n\n*** System State ***\n");
    printf("\nProcess\tAllocation\t\tMax\t\t\tNeed\n");
    
    for (i = 0; i < n; i++) {
        printf("P%d\t", i+1);
        
        // Print Allocation
        for (j = 0; j < r; j++) {
            printf("%d ", alloc[i][j]);
        }
        printf("\t\t");
        
        // Print Max
        for (j = 0; j < r; j++) {
            printf("%d ", max[i][j]);
        }
        printf("\t\t");
        
        // Print Need
        for (j = 0; j < r; j++) {
            printf("%d ", need[i][j]);
        }
        printf("\n");
    }
    
    // Print Available Resources
    printf("\nAvailable Resources: ");
    for (j = 0; j < r; j++) {
        printf("%d ", avail[j]);
    }
    printf("\n");
}

void detect_deadlock() {
    int finish[100];  // Tracks which processes can complete
    int dead_processes[100];  // List of deadlocked processes
    int count = 0;  // Number of deadlocked processes
    int work[100];  // Working copy of available resources
    int i, j, k;
    int process_completed;
    
    // Initialize work array with available resources
    for (i = 0; i < r; i++) {
        work[i] = avail[i];
    }
    
    // Initialize finish array
    for (i = 0; i < n; i++) {
        finish[i] = 0;
    }
    
    // Find processes that can finish
    process_completed = 1;
    while (process_completed) {
        process_completed = 0;
        
        for (i = 0; i < n; i++) {
            if (finish[i] == 0) {
                int can_allocate = 1;
                
                // Check if process needs can be satisfied
                for (j = 0; j < r; j++) {
                    if (need[i][j] > work[j]) {
                        can_allocate = 0;
                        break;
                    }
                }
                
                // If process can complete
                if (can_allocate) {
                    // Add allocated resources back to work
                    for (j = 0; j < r; j++) {
                        work[j] += alloc[i][j];
                    }
                    
                    finish[i] = 1;
                    process_completed = 1;
                    
                    printf("\nProcess P%d can finish", i+1);
                }
            }
        }
    }
    
    // Check for deadlock
    int deadlock = 0;
    for (i = 0; i < n; i++) {
        if (finish[i] == 0) {
            dead_processes[count++] = i;
            deadlock = 1;
        }
    }
    
    // Print results
    if (deadlock) {
        printf("\n\nSystem is in Deadlock State!\n");
        printf("Deadlocked Processes: ");
        for (i = 0; i < count; i++) {
            printf("P%d ", dead_processes[i]+1);
        }
        printf("\n");
    } else {
        printf("\n\nNo Deadlock Detected\n");
    }
}
