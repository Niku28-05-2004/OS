#include <stdio.h>
#include <stdlib.h>

void fcfs(int *requests, int n, int initial_position) {
    int total_head_movement = 0;
    
    printf("Sequence of head movement: ");
    printf("%d -> ", initial_position);
    
    for (int i = 0; i < n; i++) {
        printf("%d", requests[i]);
        if (i != n - 1)
            printf(" -> ");
        total_head_movement += abs(initial_position - requests[i]);
        initial_position = requests[i];
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
    
    fcfs(requests, n, initial_position);
    
    free(requests);
    return 0;
}




//8
// 176,79,34,60,92,11,41,114
//head=50
