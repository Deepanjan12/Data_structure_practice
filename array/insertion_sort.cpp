// Insertion Sort
#include <stdio.h>
int insertion_sort(int arr[], int n)
{
    int i, j, temp;
    for (i = 1; i < n; i++)
    {
        temp = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > temp)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = temp;
    }
}
int main()
{
    int i, n, arr[100];
    printf("Enter the limit of the array: ");
    scanf("%d", &n);
    printf("\nEnter the elements of the array: ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("\nBefore sorting the array: \n");
    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    insertion_sort(arr, n);
    printf("\nAfter sorting the array: \n");
    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\nEnd of the program ");
}
// End of the program
//Program is written by Deepanjan Sur