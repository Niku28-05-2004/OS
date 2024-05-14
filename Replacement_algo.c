#include <stdio.h>
#define MAX_FRAMES 3
#define MAX_PAGES 20

void lru(int pages[], int n);
void optimal(int pages[], int n);
void fifo(int pages[], int n);

int main() {
    int pages[MAX_PAGES];
    int n, i, choice;

    printf("Enter the number of page references: ");
    scanf("%d", &n);

    printf("Enter the page reference string: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &pages[i]);
    }

    printf("\nSelect the page replacement algorithm:\n");
    printf("1. LRU\n");
    printf("2. Optimal\n");
    printf("3. FIFO\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("\nLRU Algorithm:\n");
            lru(pages, n);
            break;
        case 2:
            printf("\nOptimal Algorithm:\n");
            optimal(pages, n);
            break;
        case 3:
            printf("\nFIFO Algorithm:\n");
            fifo(pages, n);
            break;
        default:
            printf("\nInvalid choice. Please select a valid algorithm.\n");
    }

    return 0;
}

void lru(int pages[], int n) {
    int frames[MAX_FRAMES] = {-1, -1, -1};
    int counter[MAX_FRAMES] = {0, 0, 0};
    int page_faults = 0;
    int i, j, k, least;

    for (i = 0; i < n; i++) {
        for (j = 0; j < MAX_FRAMES; j++) {
            if (frames[j] == pages[i]) {
                counter[j] = i;
                break;
            }
        }

        if (j == MAX_FRAMES) {
            least = 0;
            for (j = 1; j < MAX_FRAMES; j++) {
                if (counter[j] < counter[least]) {
                    least = j;
                }
            }
            frames[least] = pages[i];
            counter[least] = i;
            page_faults++;
        }

        printf("Page %d: ", pages[i]);
        for (k = 0; k < MAX_FRAMES; k++) {
            if (frames[k] == -1) {
                printf("- ");
            } else {
                printf("%d ", frames[k]);
            }
        }
        printf("\n");
    }

    printf("Page Faults: %d\n", page_faults);
}

void optimal(int pages[], int n) {
    int frames[MAX_FRAMES] = {-1, -1, -1};
    int page_faults = 0;
    int i, j, k, max, index;

    for (i = 0; i < n; i++) {
        for (j = 0; j < MAX_FRAMES; j++) {
            if (frames[j] == pages[i]) {
                break;
            }
        }

        if (j == MAX_FRAMES) {
            page_faults++;
            max = -1;
            index = 0;
            for (j = 0; j < MAX_FRAMES; j++) {
                int found = 0;
                for (k = i + 1; k < n; k++) {
                    if (frames[j] == pages[k]) {
                        if (k > max) {
                            max = k;
                            index = j;
                        }
                        found = 1;
                        break;
                    }
                }
                if (!found) {
                    index = j;
                    break;
                }
            }
            frames[index] = pages[i];
        }

        printf("Page %d: ", pages[i]);
        for (k = 0; k < MAX_FRAMES; k++) {
            if (frames[k] == -1) {
                printf("- ");
            } else {
                printf("%d ", frames[k]);
            }
        }
        printf("\n");
    }

    printf("Page Faults: %d\n", page_faults);
}

void fifo(int pages[], int n) {
    int frames[MAX_FRAMES] = {-1, -1, -1};
    int page_faults = 0;
    int i, j, k;

    j = 0; // FIFO queue pointer

    for (i = 0; i < n; i++) {
        for (k = 0; k < MAX_FRAMES; k++) {
            if (frames[k] == pages[i]) {
                break;
            }
        }

        if (k == MAX_FRAMES) {
            frames[j] = pages[i];
            j = (j + 1) % MAX_FRAMES;
            page_faults++;
        }

        printf("Page %d: ", pages[i]);
        for (k = 0; k < MAX_FRAMES; k++) {
            if (frames[k] == -1) {
                printf("- ");
            } else {
                printf("%d ", frames[k]);
            }
        }
        printf("\n");
    }

    printf("Page Faults: %d\n", page_faults);
}