#include<stdio.h>
int bsearch(int *a,int low,int high,int key)
{
        if(low<=high)
        {
              int mid=(low+high)/2;
             if(a[mid]==key)
             {
                 return mid;
             }
             else if(a[mid]<key)
             {
                 bsearch(a,mid+1,high,key);
             }
             else
             {
                 bsearch(a,low,mid-1,key);
             }
        }
        else
        {
             return -1;
        }
}


int main(){
    int  arr[100];
    int n;
    printf("Enter the limit of the array: ");
    scanf("%d",&n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("Enter the element to be searched: ");
    int x,pos;
    scanf("%d",&x);
    bsearch(arr,0,n-1,x);

    return 0;
}