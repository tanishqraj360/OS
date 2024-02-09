#include <stdio.h>

#define MAX_FRAMES 3
#define MAX_PAGES 10

int main() {
    int referenceString[MAX_PAGES] = {1, 3, 0, 3, 5, 6, 3, 7, 8, 5}; // Reference string
    int frames[MAX_FRAMES]; // Frames to hold pages
    int pageFaults = 0; // Count of page faults
    int nextFrameIndex = 0; // Index to keep track of the next frame to replace

    // Initialize frames with -1 to indicate empty frames
    for (int i = 0; i < MAX_FRAMES; i++) {
        frames[i] = -1;
    }

    // Simulate FIFO page replacement algorithm
    for (int i = 0; i < MAX_PAGES; i++) {
        printf("Referencing page %d...\n", referenceString[i]);

        // If the page is not in frames, replace the oldest page
        int pageFound = 0;
        for (int j = 0; j < MAX_FRAMES; j++) {
            if (frames[j] == referenceString[i]) {
                pageFound = 1; // Page found in frames
                break;
            }
        }

        if (!pageFound) {
            frames[nextFrameIndex] = referenceString[i];
            nextFrameIndex = (nextFrameIndex + 1) % MAX_FRAMES;
            pageFaults++;
            printf("Page fault occurred!\n");
        } else {
            printf("Page hit!\n");
        }

        // Print frames
        printf("Frames: ");
        for (int j = 0; j < MAX_FRAMES; j++) {
            if (frames[j] == -1) {
                printf("[ ] ");
            } else {
                printf("[%d] ", frames[j]);
            }
        }
        printf("\n\n");
    }

    printf("Total Page Faults: %d\n", pageFaults);

    return 0;
}
