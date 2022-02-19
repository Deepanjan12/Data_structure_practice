#include<stdio.h>
int sort(int arr[],int n){
    int i=0;
    while(i<n)
    {
        if (arr[i]<1)
        {
            printf("%d ",arr[i]);
        }
        if(arr[i]<2&&arr[i]==1)
            printf("%d ",arr[i]);
        if(arr[i]>1&&arr[i]==2)
            printf("%d ",arr[i]);

         i++;
    }
}


int main(){
    int n;
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    sort(arr,n);

    return 0;
}