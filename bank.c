#include <stdio.h>

int max[5][5], alloc[5][5], need[5][5], avail[5], finish[5], n, r;

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

    printf("Available:\n");
    for (int j = 0; j < r; j++)
        scanf("%d", &avail[j]);

    // Calculate need
    for (int i = 0; i < n; i++)
        for (int j = 0; j < r; j++)
            need[i][j] = max[i][j] - alloc[i][j];

    // Safety check
    int count = 0;
    while (count < n) {
        int found = 0;
        for (int i = 0; i < n; i++) {
            if (!finish[i]) {
                int ok = 1;
                for (int j = 0; j < r; j++)
                    if (need[i][j] > avail[j]) ok = 0;

                if (ok) {
                    for (int j = 0; j < r; j++)
                        avail[j] += alloc[i][j];
                    finish[i] = 1;
                    found = 1;
                    count++;
                    printf("P%d ", i);
                }
            }
        }
        if (!found) break;
    }

    if (count == n)
        printf("\nSystem is in a SAFE state.\n");
    else
        printf("\nSystem is in an UNSAFE state (Deadlock possible).\n");

    return 0;
}
