#include <stdio.h>

int max[5][5], alloc[5][5], need[5][5], avail[5], finish[5];
int n, r;

int main() {
    printf("Processes: "); 
	scanf("%d", &n);
    printf("Resources: "); 
	scanf("%d", &r);

    printf("Max matrix:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < r; j++)
            scanf("%d", &max[i][j]);

    printf("Allocation matrix:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < r; j++)
            scanf("%d", &alloc[i][j]);

    printf("Available resources:\n");
    for (int j = 0; j < r; j++)
        scanf("%d", &avail[j]);

    // Calculate need matrix
    for (int i = 0; i < n; i++)
        for (int j = 0; j < r; j++)
            need[i][j] = max[i][j] - alloc[i][j];

    // Deadlock detection
    int changed = 1;
    while (changed) {
        changed = 0;
        for (int i = 0; i < n; i++) {
            if (!finish[i]) {
                int canRun = 1;
                for (int j = 0; j < r; j++)
                    if (need[i][j] > avail[j])
                        canRun = 0;
                if (canRun) {
                    for (int j = 0; j < r; j++)
                        avail[j] += alloc[i][j];
                    finish[i] = 1;
                    changed = 1;
                }
            }
        }
    }

    // Check for deadlock
    int deadlock = 0;
    for (int i = 0; i < n; i++) {
        if (!finish[i]) {
            printf("Process P%d is in deadlock.\n", i);
            deadlock = 1;
        }
    }

    if (!deadlock)
        printf("No deadlock detected.\n");

    return 0;
}
