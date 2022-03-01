//dyanamic array probleme
#include<stdio.h>
#include<stdlib.h>
 void printarray(int arr[],int n)
 {
        for(int i=0;i<n;i++)
        {
            printf("%d ",arr[i]);
        }
        printf("\n");

 }
int insert_element(int arr[],int n,int x)
{
     arr[n]=x;
     n++;
     return n;
}
int delete_element(int arr[],int n)
{
     n--;
     return n;
}
int  insert_at_position(int arr[],int n,int x,int pos)
{
     for(int i=n;i>=pos;i--)
     {
         arr[i+1]=arr[i];
     }
     arr[pos]=x;
     n++;
     return n;
}
int  delete_at_position(int arr[],int n,int pos)
{
     for(int i=pos;i<n;i++)
     {
         arr[i]=arr[i+1];
     }
     n--;
     return n;
}
int main(){
    //dynamic allocation of array
    int *arr;
    int n,i,ch;
    int pos;
    int x, p;
    printf("\nEnter the limit of the array: ");
    scanf("%d",&n);
    arr=(int*)malloc(sizeof(int)*n);
    if(arr==NULL)
    {
        printf("\nMemory not allocated");
        exit(0);
    }
    else
    {
        printf("\nEnter the elements of the array: ");
        for(i=0;i<n;i++)
        {
            scanf("%d",&arr[i]);
        }
    }
    while(1)
    {
        printf("\n1.Insert element\n2.Delete element\n3.Insert at position\n4.Delete at position\n5.Print array\n6.Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d",&p);
        switch (ch)
        {
        case 1:
            printf("\nEnter the element to be inserted: ");
            scanf("%d",&x);
            p= insert_element(arr,n,x);
            break;
        case 2:
            delete_element(arr,n);
            break;
        case 3:
            printf("\nEnter the element to be inserted: ");
            scanf("%d",&x);
            printf("\nEnter the position: ");
            scanf("%d",&pos);
            insert_at_position(arr,p,x,pos);
            break;
        case 4:
            printf("\nEnter the position: ");
            scanf("%d",&pos);
            delete_at_position(arr,n,pos);
            break;
        case 5:
            printarray(arr,n);
            break;
        case 6:
            exit(0);
            break;

        default:
            printf("\nInvalid choice");
            break;
        }
    }
    printarray(arr,n);
    printf("\nEnter the element to be inserted: ");

    scanf("%d",&x);
    p = insert_element(arr,n,x);
    printarray(arr,p);
    p =  delete_element(arr,p);
    printf("\nEnter the position to be inserted: ");

    scanf("%d",&pos);
    printf("\nEnter the element to be inserted: ");
    scanf("%d",&x);
    p = insert_at_position(arr,p,x,pos-1);
    printarray(arr,p);
    printf("\nEnter the position to be deleted: ");
    scanf("%d",&pos);
    p = delete_at_position(arr,n,pos-1);
    printarray(arr,n);

    return 0;
}