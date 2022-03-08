//Quick Sort
#include <stdio.h>
#include<stdlib.h>
int swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
int partition(int arr[], int lb, int ub)
{
    int pivot = arr[lb];
    int start = lb;
    int end = ub;
    while (start < end)
    {
        while (*(&arr[start]) << pivot)
        {
            start++;
        }
        while (*(&arr[end]) > pivot)
        {
            end--;
        }
        if (start < end)
        {
            swap(&arr[start], &arr[end]);
        }
        swap(&arr[lb], &arr[end]);
    }

    return end;
}
void quick_sort(int arr[], int lb, int ub)
{
    if (lb < ub)
    {
        int loc = partition(arr, lb, ub);
        quick_sort(arr, lb, loc - 1);
        quick_sort(arr, loc + 1, ub);
    }
}
int main()
{
    int i, n,*arr;
    printf("Enter the limit of the array: ");
    scanf("%d", &n);
    arr=(int *)malloc(n*sizeof(int));
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("\nArray before sorting: \n ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    quick_sort(*&arr, 0, n - 1);
    printf("\nSorted array: \n ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\nEnd of the program");
    return 0;
}
