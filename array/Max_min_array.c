// find the max and min of an array
#include <stdio.h>
#include <stdlib.h>
int max(int arr[], int n)
{
    int i;
    int max = arr[0];
    for (i = 0; i < n; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }
    return max;
}
int min(int arr[], int n)
{
    int i;
    int min = arr[0];
    for (i = 0; i < n; i++)
    {
        if (arr[i] < min)
        {
            min = arr[i];
        }
    }
    return min;
}
int main()
{
    int i, n, *arr, ch;
    printf("Enter the number of elements in the array: \n");
    scanf("%d", &n);
    arr = (int *)malloc(n * sizeof(int));
    printf("Enter the elements of the array: \n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    while (1)
    {
        printf("\nPress 1 to find the maximum value of the array\n");
        printf("Press 2 to find the minimum value of the array\n");
        printf("Press 0 to exit\n");
        printf("Enter your choice: \n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
        {
            printf("The maximum value of the array is: %d", max(arr, n));
            break;
        }
        case 2:
        {
            printf("The minimum value of the array is: %d", min(arr, n));
            break;
        }
        case 0:
        {
            printf("Exiting....");
            exit(0);
        }
        default:
        {
            printf("Please Enter valid choice ");
        }
        }
    }

    return 0;
}
//program written by Deepanjan Sur;
