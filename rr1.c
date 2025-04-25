#include <stdio.h>
int main() {
    int i, n, time_slice, remaining_processes, time = 0;
    int bt[10], wt[10], tat[10], rem_bt[10]; 
    float total_wt = 0, total_tat = 0;

    // Input: Number of processes
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    // Input: Burst times
    for (i = 0; i < n; i++) {
        printf("Enter Burst Time for process %d: ", i + 1);
        scanf("%d", &bt[i]);
        rem_bt[i] = bt[i];  // Store burst time for reference
    }
    // Input: Time slice (quantum)
    printf("\nEnter the time slice: ");
    scanf("%d", &time_slice);
    remaining_processes = n;  // Number of remaining processes
    // Round Robin Scheduling Execution
    while (remaining_processes > 0) {
        for (i = 0; i < n; i++) {
            if (rem_bt[i] > 0) {  // If process still has burst time remaining
                if (rem_bt[i] <= time_slice) {
                    time += rem_bt[i];  // Process finishes
                    tat[i] = time;       // Turnaround time
                    rem_bt[i] = 0;       // Mark process as completed
                    remaining_processes--;  // Reduce process count
                } else {
                    time += time_slice;  // Process runs for time slice
                    rem_bt[i] -= time_slice;  // Reduce remaining burst time
                }
            }
        }
    }
    // Calculate Waiting Time (WT) and Average Times
    for (i = 0; i < n; i++) {
        wt[i] = tat[i] - bt[i];  // WT = Turnaround Time - Burst Time
        total_wt += wt[i];
        total_tat += tat[i];
    }
    // Output results
    printf("\nProcess\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (i = 0; i < n; i++) {
        printf("%d\t%d\t\t%d\t\t%d\n", i + 1, bt[i], wt[i], tat[i]);
    }
    printf("\nAverage Waiting Time: %.2f", total_wt / n);
    printf("\nAverage Turnaround Time: %.2f\n", total_tat / n);
    return 0;
}

