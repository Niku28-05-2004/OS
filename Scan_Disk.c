// SCAN disk scheduling algorithm

#include <stdio.h>
#include <stdlib.h>

//#define SIZE 8
#define DISK_SIZE 200

void sort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void SCAN(int arr[], int head, char* direction, int SIZE) {
    int seek_count = 0;
    int distance, cur_track;
    int left[SIZE], right[SIZE];
    int left_size = 0, right_size = 0;
    int seek_sequence[SIZE * 2];
    int seek_sequence_size = 0;

    // Appending end values which have to be visited before reversing the direction
    if (strcmp(direction, "left") == 0) {
        left[left_size++] = 0;
    } else if (strcmp(direction, "right") == 0) {
        right[right_size++] = DISK_SIZE - 1;
    }

    for (int i = 0; i < SIZE; i++) {
        if (arr[i] < head)
            left[left_size++] = arr[i];
        if (arr[i] > head)
            right[right_size++] = arr[i];
    }

    // Sorting left and right arrays
    sort(left, left_size);
    sort(right, right_size);

    // Run the while loop two times, scanning right and left of the head
    for (int run = 0; run < 2; run++) {
        if (strcmp(direction, "left") == 0) {
            for (int i = left_size - 1; i >= 0; i--) {
                cur_track = left[i];
                seek_sequence[seek_sequence_size++] = cur_track;
                distance = abs(cur_track - head);
                seek_count += distance;
                head = cur_track;
            }
            strcpy(direction, "right");
        } else if (strcmp(direction, "right") == 0) {
            for (int i = 0; i < right_size; i++) {
                cur_track = right[i];
                seek_sequence[seek_sequence_size++] = cur_track;
                distance = abs(cur_track - head);
                seek_count += distance;
                head = cur_track;
            }
            strcpy(direction, "left");
        }
    }

    printf("Total number of seek operations = %d\n", seek_count);
    printf("Seek Sequence is:\n");

    for (int i = 0; i < seek_sequence_size; i++) {
        printf("%d\n", seek_sequence[i]);
    }
}

int main() {
    int SIZE;// =8;
    printf("Enter size: ");
    scanf("%d",&SIZE);
    int arr[SIZE] ;//= { 176, 79, 34, 60, 92, 11, 41, 114 };
    int head ;//= 50;
    printf("Enter track :");
    for(int i=0; i<SIZE;i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("Enter head :");
    scanf("%d",&head);

    char direction[10] = "left";

    SCAN(arr, head, direction,SIZE);

    return 0;
}