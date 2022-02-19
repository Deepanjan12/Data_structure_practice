// queue using single linked list
#include<stdio.h>
#include<stdlib.h>
    struct Node
{
    int data;
    Node *next;
}*front=NULL,*rear=NULL;
void insert()
{
    Node *newNode=(struct Node*)malloc(sizeof(struct Node));
    printf("\nEnter the Data: ");
    scanf("%d",&newNode->data);
    newNode->next=NULL;
    if(rear==NULL)
    {
        front =newNode;
        rear=newNode;
    }
    else
    {
        rear->next=newNode;
        rear=newNode;
    }
    printf("\ninsertion is sucessfull");
}
void Queue_delete()
{
    if(front==NULL)
    printf("\nQueue is empty");
    else
    {
        Node  *temp=front;
        front =front->next;
        printf("%d is deleted",temp->data);
        free(temp);
    }
}
void display()
{
    if(front ==NULL)
    {
        printf("\nQueue is empty");
    }
    else
    {
        Node *temp= front;
        while(temp->next!=NULL)
        {
            printf("%d->\t",temp->data);
            temp=temp->next;
        }
        printf("%d->   NULL",temp->data);
    }
}
int main()
{
    int ch;
    while(1)
    {
        printf("\n1. Insert\n2. Delete\n3. Display\n4. Exit");
        printf("\nmake Choice: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            insert();
            break;
        case 2:
            Queue_delete ();
            break;
        case 3:
            display();
            break;
        case 4:
            exit(0);
             default : printf("\nInavlid choice");
            break;
        }
    }
}



