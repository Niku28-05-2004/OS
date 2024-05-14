// CSCAN disk scheduling algorithm

// CSCAN disk scheduling algorithm

#include <stdio.h>
#include <stdlib.h>

// Size of the disk
#define SIZE_DISK 200

// Function to swap two integers
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to sort an array
void sort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}

// C-SCAN algorithm
void c_scan_algorithm(int arr[], int N, int initial) {
    // Sorting the initial array of requests
    sort(arr, N);

    // Stores the order in which requests are processed
    int order[N + 2];
    int orderIndex = 0;

    // Stores the total head movement
    int total = 0;

    // Extract the first request with a value greater than or equal to the head and calculating the requests
    int last = initial;
    for (int i = 0; i < N; i++) {
        if (arr[i] >= initial) {
            total += (arr[i] - last);
            order[orderIndex++] = arr[i];
            last = arr[i];
        }
    }

    // Reaching the end of the disk
    total += (SIZE_DISK - last - 1);
    order[orderIndex++] = SIZE_DISK - 1;

    // Reaching the starting of the disk
    total += (SIZE_DISK - 1 - 0);
    order[orderIndex++] = 0;

    // Extract the requests with a value less than or equal to the head and calculate the requests
    last = 0;
    for (int i = 0; i < N; i++) {
        if (arr[i] < initial) {
            total += (arr[i] - last);
            order[orderIndex++] = arr[i];
            last = arr[i];
        } else {
            break; // Already processed requests
        }
    }

    // Printing the order of requests
    printf("The order in which requests are processed:\n");
    for (int i = 0; i < orderIndex; i++) {
        printf("%d -> ", order[i]);
    }
    printf("\n\n");

    // Printing the total head movement
    printf("Total head movement = %d\n", total);
}

// Driver function
int main() {
    // Total number of requests
    int N;
    printf("enter n :");
    scanf("%d",&N);

    // Request Array
    int arr[N];
    printf("Enter track : \n");
    for(int i=0;i<N;i++)
    {
        scanf("%d",&arr[i]);
    }
    

    // Initial position of the head pointer
    int initial ;
    printf("enter initial position :");
    scanf("%d",&initial);

    // Calling the function
    c_scan_algorithm(arr, N, initial);

    return 0;
}
    //8
// 176,79,34,60,92,11,41,114
//head=50