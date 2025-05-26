#include <stdio.h>

int n, r, max[100][100], alloc[100][100], need[100][100], avail[100], finish[100];

int main() {
    printf("Processes: "); scanf("%d", &n);
    printf("Resources: "); scanf("%d", &r);

    printf("Max Matrix:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < r; j++)
            scanf("%d", &max[i][j]);

    printf("Allocation Matrix:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < r; j++) {
            scanf("%d", &alloc[i][j]);
            need[i][j] = max[i][j] - alloc[i][j];
        }

    printf("Available Resources:\n");
    for (int j = 0; j < r; j++)
        scanf("%d", &avail[j]);

    int done;
    do {
        done = 0;
        for (int i = 0; i < n; i++) {
            if (!finish[i]) {
                int can_finish = 1;
                for (int j = 0; j < r; j++)
                    if (need[i][j] > avail[j]) can_finish = 0;
                if (can_finish) {
                    for (int j = 0; j < r; j++)
                        avail[j] += alloc[i][j];
                    finish[i] = 1;
                    done = 1;
                    printf("P%d finished\n", i + 1);
                }
            }
        }
    } while (done);

    int deadlock = 0;
    for (int i = 0; i < n; i++)
        if (!finish[i]) {
            if (!deadlock) printf("Deadlocked: ");
            printf("P%d ", i + 1);
            deadlock = 1;
        }

    if (!deadlock) printf("No Deadlock Detected\n");
    else printf("\n");

    return 0;
}
