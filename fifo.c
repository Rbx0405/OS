#include <stdio.h>

int main() {
    int pages[50], frame[5], n, f, i, j = 0, hit, faults = 0;

    // Input number of pages
    printf("Pages: ");
    scanf("%d", &n);
    
    // Input page reference string
    printf("Enter the page reference string:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &pages[i]);
    }

    // Input number of frames
    printf("Frames: ");
    scanf("%d", &f);

    // Initialize all frames to -1 (empty)
    for (i = 0; i < f; i++) {
        frame[i] = -1;
    }

    // FIFO Algorithm
    for (i = 0; i < n; i++) {
        hit = 0;

        // Check if page is already in frame (hit)
        for (int k = 0; k < f; k++) {
            if (frame[k] == pages[i]) {
                hit = 1;
                break;
            }
        }

        // If it's a miss, replace the oldest page
        if (!hit) {
            frame[j] = pages[i];
            j = (j + 1) % f; // Circular increment
            faults++;
        }
    }

    // Output total page faults
    printf("Page Faults: %d\n", faults);

    return 0;
}
