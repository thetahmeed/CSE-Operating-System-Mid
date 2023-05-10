#include <stdio.h>
#include <stdlib.h>

#define MAX_JOBS 50

int main()
{
    int jobCount, arrTime[MAX_JOBS], surTime[MAX_JOBS], startTime[MAX_JOBS], finTime[MAX_JOBS], idleTimes[MAX_JOBS], turnTime[MAX_JOBS];
    double avgWT = 0, avgTT = 0;

    printf("Please insert the number of job: ");
    scanf("%d", &jobCount);

    printf("\nPlease insert the Arrival Times\n");
    for (int i = 0; i < jobCount; i++)
    {
        scanf("%d", &arrTime[i]);
    }

    printf("\nPlease inset the Service Times: ");
    for (int i = 0; i < jobCount; i++)
    {
        scanf("%d", &surTime[i]);
    }

    // Calculating the finish time
    for (int i = 0; i < jobCount; i++)
    {
        int idleTime = 0;

        if (i > 1)
        {
            idleTime = arrTime[i] - finTime[i - 1];
        }
        finTime[i] = arrTime[i] + surTime[i];

        if (idleTime < 1)
        {
            finTime[i] = finTime[i] + abs(idleTime);
        }
    }

    // Calculating the start time
    for (int i = 0; i < jobCount; i++)
    {
        if (i == 0)
        {
            startTime[i] = arrTime[i];
        }
        else
        {
            startTime[i] = finTime[i - 1];
        }
    }

    // Shiwing gantt chart
    printf("\nThe gantt chart\n");
    printf("Start time\t\tJob name\t\tFinish time");
    for (int i = 0; i < jobCount; i++)
    {
        printf("\n%d\t\t\tJob %d\t\t\t%d", startTime[i], i + 1, finTime[i]);
    }

    // Calculating the wait time
    for (int i = 0; i < jobCount; i++)
    {
        if (i > 0)
        {
            idleTimes[i] = finTime[i - 1] - arrTime[i];
        }
        else
        {
            // At the biggining no idle time
            idleTimes[i] = 0;
        }

        if (idleTimes[i] < 1)
        {
            idleTimes[i] = 0;
        }
    }

    // Calculating tern around times:
    for (int i = 0; i < jobCount; i++)
    {
        turnTime[i] = finTime[i] - arrTime[i];
    }

    // calculating avgWT
    printf("Arrival time\t\tSurvice time\t\tFinish time\t\tWating time\t\tTurn around time\n");
    for (int i = 0; i < jobCount; i++)
    {
        printf("%d\t\t\t%d\t\t\t%d\t\t\t%d\t\t\t%d\n", arrTime[i], surTime[i], finTime[i], idleTimes[i], turnTime[i]);
    }

    int total = 0;
    for (int i = 0; i < jobCount; i++)
    {
        total = total + idleTimes[i];
    }
    avgWT = (double)total / jobCount;
    printf("\nAvg wait time = %.2f", avgWT);

    // calculating avgTT
    total = 0;
    for (int i = 0; i < jobCount; i++)
    {
        total = total + turnTime[i];
    }
    avgTT = (double)total / jobCount;
    printf("\nAvg turn around time = %.2f", avgTT);

    return 0;
}
