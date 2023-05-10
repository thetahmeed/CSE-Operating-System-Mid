#include <stdio.h>
using namespace std;
int main()
{
    int n, arrTimes[10], serTimes[10], w[10], t[10], At[10], sum_w = 0, sum_t = 0, i, j, temp = 0, temp1 = 0, temp2 = 0;
    float avg_w, avg_t;
    printf("Enter the job count: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        printf("\nEnter Arrival time of Job %d:", i + 1);
        scanf("%d", &At[i]);
    }

    for (i = 0; i < n; i++)
    {
        printf("\nEnter service time of Job %d:", i + 1);
        scanf("%d", &serTimes[i]);
    }

    arrTimes[0] = 1;
    for (i = 1; i < n; i++)
    {
        arrTimes[i] = i + 1;
    }
    for (i = 1; i < n; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (serTimes[i] > serTimes[j])
            {
                temp = serTimes[i];
                serTimes[i] = serTimes[j];
                serTimes[j] = temp;
                temp1 = arrTimes[i];
                arrTimes[i] = arrTimes[j];
                arrTimes[j] = temp1;
                temp2 = At[i];
                At[i] = At[j];
                At[j] = temp2;
            }
        }
    }

    w[0] = 0 - At[0];
    for (i = 1; i < n; i++)
    {
        w[i] = w[i - 1] + serTimes[i - 1];
    }
    for (i = 1; i < n; i++)
    {
        w[i] = w[i] - At[i];
        sum_w = sum_w + w[i];
    }
    for (i = 0; i < n; i++)
    {
        t[i] = w[i] + serTimes[i];
        sum_t = sum_t + t[i];
    }

    printf("\nGrandChart: \n");

    printf("|");
    for (i = 0; i < n; i++)
    {
        printf(" Job %d  | ", arrTimes[i]);
    }

    printf("\n0\t");

    for (i = 0; i < n; i++)
    {
        printf(" %d\t", t[i] + At[i]);
    }

    printf("\nArrival time\t\tService time\t\tWait time\t\tTurnaround time\n");
    for (i = 0; i < n; i++)
    {
        printf("Job %d\t\t\t%d\t\t\t%d\t\t\t%d", arrTimes[i], serTimes[i], w[i], t[i]);
        printf("\n");
    }
    avg_w = (float)sum_w / n;
    avg_t = (float)sum_t / n;
    printf("average waiting time=%.2f\n", avg_w);
    printf("average turnaround time=%.2f\n", avg_t);
}