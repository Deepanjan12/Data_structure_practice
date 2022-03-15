#include <stdio.h>
#include <stdlib.h>
struct work
{
    char job[20];
    int deadline;
    int profit;
};
int sort(struct work a[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (a[j].profit < a[j + 1].profit)
            {
                struct work temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
    return 0;
}
int main()
{
    int n;
    printf("\nEnter the number of jobs: ");
    scanf("%d", &n);
    struct work a[n];
    for (int i = 0; i < n; i++)
    {
        printf("\nEnter the details of job %d: ", i + 1);
        printf("\nEnter the name of the job: ");
        scanf("%s", a[i].job);
        printf("\nEnter the deadline of the job: ");
        scanf("%d", &a[i].deadline);
        printf("\nEnter the profit of the job: ");
        scanf("%d", &a[i].profit);
    }
    sort(a, n);
    printf("\nThe jobs in order of profit are: ");
    int temp[n];
    for (int i = 0; i < n; i++)
    {
        temp[i] = a[i].profit;
        printf("\n%s", a[i].job);
    }
    printf("\n");
    int out[n + 1];
    for (int i = 0; i <= n; i++)
    {
        out[i] = -1;
    }
    for (int i = 0; i < n; i++)
    {
        int pos = a[i].deadline;
        if (out[pos] == -1)
        {
            out[pos] = i;
        }
        else
        {
            for (int j = 1; j < pos; j++)
            {
                if (out[j] == -1)
                {
                    out[j] = i;
                    break;
                }
            }
        }
    }
    int sum = 0;
    printf("\nOptimal Schedule is: ");
    for (int i = 0; i <= n; i++)
    {
        if (out[i] != -1)
        {
            printf("\n%s", a[out[i]].job);
            sum += a[out[i]].profit;
        }
    }
    printf("\nmaximum earned profit: %d", sum);
    for (int i = 0; i < n; i++)
    {
        if (a[i].deadline == out[i])
        {
            printf("\nThe job %s canont be completed within deadline", a[i].job);
        }
    }
    return 0;
}