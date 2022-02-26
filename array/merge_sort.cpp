//Merge Sort
#include<stdio.h>
int  merge(int arr[],int lb,int mid, int ub)
{
    int i=lb,j=mid+1,k=lb,b[100];

    while(i<=mid && j<=ub)
    {
        if(arr[i]<=arr[j])
        {
            b[k]=arr[i];
            i++;
        }
        else
        {
            b[k]=arr[j];
            j++;
        }
        k++;
    }
    if(i>mid)
    {
	    while(j<=ub)
	    {
	        b[k]=arr[j];
	        j++;
	        k++;
	    }
	}
	else{

		while(i<=mid)
    	{
        b[k]=arr[i];
        i++;
        k++;
    	}
	}
   	for(k=lb;k<=ub;k++)
   	{
   		arr[k]=b[k];
	}
}
void merge_sort(int arr[],int lb,int ub)
{
    if(lb<ub)
    {
        int mid=(lb+ub)/2;
        merge_sort(arr,lb,mid);
        merge_sort(arr,mid+1,ub);
        merge(arr,lb,mid,ub);
    }
}
int main()
{
    int n;
    printf("Enter the limit of the array: ");
    scanf("%d",&n);
    int  arr[100];
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("\nArray before sorting:\n ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    merge_sort(arr,0,n-1);
    printf("\nSorted array: \n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ",arr[i]);
    }

    printf("\n\nEnd of the program \nProgram is written by Deepanjan Sur");
    return 0;
}

/*Program is witten by Deepanjan Sur
*/