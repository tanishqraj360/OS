#include <stdio.h>
#define MAX_PROCESSES 10
#define TIME_QUANTUM 4

int main()
{
    int n, i;

    // Input number of processes
    printf("Enter the number of processes:");
    scanf("%d", &n);

    // Declare arrays to store burst times and calculated times
    int burstTimes[MAX_PROCESSES];
    int remainingBurst[MAX_PROCESSES];
    int waitingTimes[MAX_PROCESSES];
    int turnaroundTimes[MAX_PROCESSES];

    // Input burst times
    printf("Enter burst times for each process: \n");
    for (i = 0; i < n; i++)
    {
        printf("Burst Time for process %d: ", i + 1);
        scanf("%d", &burstTimes[i]);
        remainingBurst[i] = burstTimes[i];
        waitingTimes[i] = 0;
        turnaroundTimes[i] = 0;
    }

    // Perform Round Robin scheduling
    int time = 0;
    int done = 0;

    while (!done)
    {
        done = 1;

        for (i = 0; i < n; i++)
        {
            if (remainingBurst[i] > 0)
            {
                done = 0;

                if (remainingBurst[i] > TIME_QUANTUM)
                {
                    // Process executes for TIME_QUANTUM time units
                    time += TIME_QUANTUM;
                    remainingBurst[i] -= TIME_QUANTUM;
                }
                else
                {
                    // Process finishes execution
                    time += remainingBurst[i];
                    waitingTimes[i] = time - burstTimes[i];
                    remainingBurst[i] = 0;
                    turnaroundTimes[i] = waitingTimes[i] + burstTimes[i];
                }
            }
        }
    }

    // Display results
    printf("%-20s %-20s %-20s %-20s\n", "Process", "Burst Time", "Waiting Time", "Turnaround Time");
    for (i = 0; i < n; i++)
    {
        printf("%-20d %-20d %-20d %-20d\n", i + 1, burstTimes[i], waitingTimes[i], turnaroundTimes[i]);
    }

    // Calculate averages
    float avgWaitingTime = 0, avgTurnaroundTime = 0;
    for (i = 0; i < n; i++)
    {
        avgWaitingTime += waitingTimes[i];
        avgTurnaroundTime += turnaroundTimes[i];
    }
    avgWaitingTime /= n;
    avgTurnaroundTime /= n;

    printf("\nAverage Waiting Time: %.2f\n", avgWaitingTime);
    printf("Average Turnaround Time: %.2f\n", avgTurnaroundTime);

    return 0;
}
