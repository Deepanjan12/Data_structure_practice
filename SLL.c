#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int data;
    struct Node*next;
}*head=NULL,*tail=NULL;
int count;
void add()
{
    struct Node *a=(struct Node*)malloc(sizeof(struct Node));
    printf("\nEnter Your Node Value:\t");
    scanf("%d",&a->data);
    a->next=NULL;
    if(head==NULL)
    {
        head = a;
        tail = a;
        return;
    }
    else
    {
        tail->next=a;
        tail=a;
    }
    count ++;
}
void display(struct Node *a)
{
        if(head==NULL)
        {
            printf("\nList is Empty");
            return;
        }
        else
        {
            while(a!=NULL)
            {
                printf("%d->", a->data);
                a = a->next;
            }
            printf("\n%d",count);

        }
}
void reverse(struct Node *p)
{
    //1->2->3->4->5
    //1<-2<-3<-4<-5
    //1->2<-3<-4<-5
    if(p==NULL)
    {
        printf("\nList is empty");
        return ;
    }
    else if(p->next==NULL){
        head=p;
        return;
    }
    reverse(p->next);
    p->next->next=p;
    p->next=NULL;
}
void search()
{
    int data,flag=0,count=0;
    char ch1;
    struct Node *temp=head;
    printf("\nEnter the data want to find:\t");
    scanf("%d",&data);
    while(temp!=NULL)
    {
        if(temp->data==data)
        {
            flag=1;
            break;
        }
        count++;
        temp=temp->next;
    }
        if(flag==1)
        {
            printf("\n%d is found at %d",temp->data,count+1);


        }
        else
        {
            printf("\nEntered Data is Not found in the list");
        }
}

int main()
{
    int ch;
    while(1)
    {
        printf("\nAdd=1\ndisplay=2\nreverse=3\nsearch=4\nexit=\t");
        scanf("%d",&ch);
        switch (ch)
        {
        case 1:
            add();
            break;
        case 2:
            display(head);
            break;
        case 3:
            reverse(head);
            break;
        case 4:
            search();
        case 5:
            exit(0);
            break;
        default:
        printf("\nInvalid choice");
            break;
        }
    }
}

