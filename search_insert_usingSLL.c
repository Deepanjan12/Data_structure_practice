#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
} *head = NULL, *tail = NULL;
int Add()
{
    struct Node *a = (struct Node *)malloc(sizeof(struct Node));
    printf("\nEnter Your Node Value:\t");
    scanf("%d", &a->data);
    a->next = NULL;
    if (head == NULL)
    {
        head = a;
        tail = a;
        return;
    }
    else
    {
        tail->next = a;
        tail = a;
    }
}
void display(struct Node *a)
{
    if (head == NULL)
    {
        printf("\nList is Empty");
        return;
    }
    else
    {
        while (a != NULL)
        {
            printf("%d->", a->data);
            a = a->next;
        }

    }
}
void search()
{
    int ser_val;
    struct Node*p;
    p=head;
    printf("\nEnter the value want to search:\t");
    scanf("%d",&ser_val);
    while(p!=NULL){
        if(p->data==ser_val)
        {
            printf("\n %d is spotted",p->data);
        }
        p=p->next;

    }
   Add();
   tail->next=p->next;
}


int main()
{
    int ch;
    while(1){
    printf("\nPress 1 = Add\nPress 2 = search and Add\nPress 3 Display\nPress 4=Exit\n Make Choice:\t");
    scanf("%d",&ch);
    switch (ch)
    {
    case 1:
       Add();
        break;
    case 2:
        search();
         break;
    case 3:
        display(head);
         break;
    case 4:
        exit(0);
         break;
    default:
    printf("\nWrong Choice");
        break;
    }
    }
}