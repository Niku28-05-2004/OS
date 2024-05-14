#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>

void sstf(int *requests, int n, int initial_position) {
    bool visited[n];
    for (int i = 0; i < n; i++)
        visited[i] = false;

    int total_head_movement = 0;
    int current_position = initial_position;

    printf("Sequence of head movement: %d -> ", current_position);

    for (int i = 0; i < n; i++) {
        int min_distance = INT_MAX;
        int next_request_index;

        for (int j = 0; j < n; j++) {
            if (!visited[j]) {
                int distance = abs(current_position - requests[j]);
                if (distance < min_distance) {
                    min_distance = distance;
                    next_request_index = j;
                }
            }
        }

        total_head_movement += min_distance;
        current_position = requests[next_request_index];
        visited[next_request_index] = true;

        printf("%d", current_position);
        if (i != n - 1)
            printf(" -> ");
    }

    printf("\nTotal head movement: %d\n", total_head_movement);
}

int main() {
    int n;

    printf("Enter the number of requests: ");
    scanf("%d", &n);

    int *requests = (int *)malloc(n * sizeof(int));

    printf("Enter the requests:\n");
    for (int i = 0; i < n; i++) {
        printf("Request %d: ", i + 1);
        scanf("%d", &requests[i]);
    }

    int initial_position;
    printf("Enter the initial position of the head: ");
    scanf("%d", &initial_position);

    sstf(requests, n, initial_position);

    free(requests);
    return 0;
}


//8
// 176,79,34,60,92,11,41,114
//head=50