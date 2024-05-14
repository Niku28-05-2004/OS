#include <stdio.h>

int main() {
    int n, i, bt[10], wt[10], tat[10], ct[10], total_wt = 0, total_tat = 0;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    printf("Enter burst times for processes:\n");
    for (i = 0; i < n; i++) {
        printf("Process[%d]: ", i + 1);
        scanf("%d", &bt[i]);
    }

    // Calculate waiting time for each process
    wt[0] = 0;  // Waiting time for first process is always 0
    for (i = 1; i < n; i++) {
        wt[i] = bt[i - 1] + wt[i - 1];
    }

    // Calculate completion time and turnaround time for each process
    for (i = 0; i < n; i++) {
        ct[i] = bt[i] + wt[i];
        tat[i] = ct[i] - bt[i];  // Turnaround time = Completion time - Burst time
    }

    // Calculate total waiting time and turnaround time
    for (i = 0; i < n; i++) {
        total_wt += wt[i];
        total_tat += tat[i];
    }

    // Display process details
    printf("Process\t Burst Time\t Waiting Time\t Completion Time\t Turnaround Time\n");
    for (i = 0; i < n; i++) {
        printf("P[%d]\t\t %d\t\t %d\t\t %d\t\t\t %d\n", i + 1, bt[i], wt[i], ct[i], tat[i]);
    }

    // Calculate average waiting time and turnaround time
    float avg_wt = (float)total_wt / n;
    float avg_tat = (float)total_tat / n;

    printf("Average Waiting Time = %.2f\n", avg_wt);
    printf("Average Turnaround Time = %.2f\n", avg_tat);

    return 0;
}
