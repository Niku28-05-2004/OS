#include <stdio.h>

int main()
{
    int pro[3] = {1, 2, 3};
    int res[3] = {1, 2, 3};

    int allocation[3][2];
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            if (j == 0)
            {
                allocation[i][j] = pro[i];
            }
            else
            {
                allocation[i][j] = res[i];
                printf("Process %d aquire resource %d\n", allocation[i][j - 1], allocation[i][j]);
            }
        }
    }

    int request[3][2];
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            if (j == 0)
            {
                request[i][j] = pro[i];
            }
            else
            {
                request[i][j] = res[i+1];
                printf("Process %d request for resource %d\n", request[i][j - 1], request[i][j]);
            }
        }
    }
 ///   printf("\nSoham = %d %d\n",res[3],res[4]);

    for (int i = 0; i < 3; i++)
    {
        for (int k = 0; k < 3; k++)
        {
            if (request[i][1] == allocation[k][1] && i != k)
            {
                printf("Deadlock occurs for process %d as resource %d is already acquired by process %d\n", request[i][1 - 1], allocation[k][1], pro[k]);
            }
        }
    }
}