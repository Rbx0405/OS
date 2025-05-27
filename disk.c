#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, cur, total = 0, req[50];
    printf("Head pos: ");
    scanf("%d", &cur);
    printf("No req: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) 
          scanf("%d", &req[i]);
    for (int i = 0; i < n; i++) {
        total += abs(req[i] - cur);
        printf("%d->%d\n", cur, req[i]);
        cur = req[i];
    }
    printf("Total: %d\n", total);
    return 0;
}

