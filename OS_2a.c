#include <stdio.h>
int main()
{
    int pid[15];
    int bt[15];
    int n;
    printf("Enter the number of process: \n");
    scanf("%d", &n);
    printf("Enter the ID of all the processes: \n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &pid[i]);
    }
    printf("Enter the Burst Time of all the processes: \n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &bt[i]);
    }
    int i, wt[n];
    wt[0] = 0;
    for (i = 1; i < n; i++)
    {
        wt[i] = bt[i - 1] + wt[i - 1];
    }

    printf("%-10s %-10s %-10s %-10s\n", "Process ID", "Burst Time", "Waiting Time", "Turnaround Time");
    float twt = 0, tat = 0;
    for (int i = 0; i < n; i++)
    {
        printf("%-12d", pid[i]);
        printf("%-11d", bt[i]);
        printf("%-13d", wt[i]);
        printf("%-10d", bt[i] + wt[i]);
        printf("\n");
        twt += wt[i];
        tat += (wt[i] + bt[i]);
    }
    float att, awt;
    awt = twt / n;
    att = tat / n;
    printf("\nThe Average Wait Time = %f", awt);
    printf("\nThe Average Turnaround Time = %f\n", att);
}