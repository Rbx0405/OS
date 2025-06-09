#include <stdio.h>

int main() {
    int n, tq, i, time = 0;
    
    printf("Enter number of processes: ");
    scanf("%d", &n);
    
    int bt[n], rem_bt[n], wt[n], tat[n];
    
    // Input burst times
    printf("Enter burst times:\n");
    for(i = 0; i < n; i++) {
        printf("P%d: ", i+1);
        scanf("%d", &bt[i]);
        rem_bt[i] = bt[i]; // Copy to remaining time array
    }
    
    printf("Enter time quantum: ");
    scanf("%d", &tq);
    
    // Round Robin execution
    int complete = 0;
    while(complete != n) {
        for(i = 0; i < n; i++) {
            if(rem_bt[i] > 0) {
                if(rem_bt[i] > tq) {
                    time += tq;
                    rem_bt[i] -= tq;
                } else {
                    time += rem_bt[i];
                    wt[i] = time - bt[i]; // waiting time = completion time - burst time
                    rem_bt[i] = 0;
                    complete++;
                }
            }
        }
    }
    
    // Calculate turnaround times and display
    printf("\nProcess\tBT\tWT\tTAT\n");
    float avg_wt = 0, avg_tat = 0;
    
    for(i = 0; i < n; i++) {
        tat[i] = bt[i] + wt[i];
        avg_wt += wt[i];
        avg_tat += tat[i];
        printf("P%d\t%d\t%d\t%d\n", i+1, bt[i], wt[i], tat[i]);
    }
    
    printf("\nAverage Waiting Time: %.2f\n", avg_wt/n);
    printf("Average Turnaround Time: %.2f\n", avg_tat/n);
    
    return 0;
}
