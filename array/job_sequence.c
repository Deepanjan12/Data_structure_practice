#include <stdio.h>

#define MAX 100

typedef struct Job
{
    char id[5];
    int deadline;
    int profit;
} Job;

void jobSequencingWithDeadline(Job jobs[], int n);

int minValue(int x, int y)
{
    if (x < y)
        return x;
    return y;
}

int main(void)
{

    int i, j, n;
    printf("Enter the number of jobs: ");
    scanf("%d", &n);
    Job jobs[n];
    for (i = 0; i < n; i++)
    {
        printf("\nEnter the details of job %d: ", i + 1);
        printf("\nEnter the name of the job: ");
        scanf("%s", jobs[i].id);
        printf("\nEnter the deadline of the job: ");
        scanf("%d", &jobs[i].deadline);
        printf("\nEnter the profit of the job: ");
        scanf("%d", &jobs[i].profit);
    }

    Job temp;

    for (i = 1; i < n; i++)
    {
        for (j = 0; j < n - i; j++)
        {
            if (jobs[j + 1].profit > jobs[j].profit)
            {
                temp = jobs[j + 1];
                jobs[j + 1] = jobs[j];
                jobs[j] = temp;
            }
        }
    }

    printf("%10s %d %d\n", "Job", "Deadline", "Profit");
    for (i = 0; i < n; i++)
    {
        printf("%10s %d %d\n", jobs[i].id, jobs[i].deadline, jobs[i].profit);
    }

    jobSequencingWithDeadline(jobs, n);

    return 0;
}

void jobSequencingWithDeadline(Job jobs[], int n)
{

    int i, j = 0, k, maxprofit;

    int timeslot[MAX];

    int filledTimeSlot = 0;

    int notprocessed[MAX / 2];

    int dmax = 0;
    for (i = 0; i < n; i++)
    {
        if (jobs[i].deadline > dmax)
        {
            dmax = jobs[i].deadline;
        }
    }

    for (i = 1; i <= dmax; i++)
    {
        timeslot[i] = -1;
    }

    printf("dmax: %d\n", dmax);

    for (i = 1; i <= n; i++)
    {
        k = minValue(dmax, jobs[i - 1].deadline);
        while (k >= 1)
        {
            if (timeslot[k] == -1)
            {
                timeslot[k] = i - 1;
                filledTimeSlot++;
                break;
            }
            k--;
        }
        if (k < 1)
        {
            notprocessed[j] = i;
        }

        if (filledTimeSlot == dmax)
        {
            if (i < n)
            {
                notprocessed[j] = i;
            }
            break;
        }
    }

    printf("\nRequired Jobs: ");
    for (i = 1; i <= dmax; i++)
    {
        printf("%s", jobs[timeslot[i]].id);

        if (i < dmax)
        {
            printf(" --> ");
        }
    }

    maxprofit = 0;
    for (i = 1; i <= dmax; i++)
    {
        maxprofit += jobs[timeslot[i]].profit;
    }
    printf("\nMax Profit: %d\n", maxprofit);

    printf("\nJobs not processed: %s", jobs[notprocessed[j]].id);
}