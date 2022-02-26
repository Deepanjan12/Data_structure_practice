//recursive bubble sort
#include<stdio.h>
int swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
int bubble_sort(int arr[],int n)
{
    if(n==1)
    {
        return 0;
    }
    int i;
    for(i=0;i<n-1;i++)
    {
        if(arr[i]>arr[i+1])
        {
            swap(&arr[i],&arr[i+1]);
        }
    }
    bubble_sort(arr,n-1);
}
int main()
{
    int i,n,arr[100];
    printf("Enter the limit of the array: ");
    scanf("%d",&n);
    printf("\nEnter the elements of the array: ");
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("\nArray Before sorting: \n ");
    for(i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
    bubble_sort(arr,n);
    printf("\nArray After sorting: \n ");
    for(i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
    return 0;
}