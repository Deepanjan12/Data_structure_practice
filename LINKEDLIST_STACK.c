#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
} *head = NULL;
void push()
{
    //1 2 3 4 5   h=1
    //7-> 1-> 2-> 3-> 4-> 5->
    //1->2->3......
    struct Node *a=(struct Node*)malloc(sizeof(struct Node));
    printf("\nEnter the value to push: ");
    scanf("%d",&a->data);
    a->next=NULL;
    if(head==NULL)
    {
        head=a;
        return;
    }
    else
    {
        a->next=head;
        head=a;
    }
}
void pop()
{
    if(head==NULL)
    {
        printf("\nNo element in stack. Pop is not possible");
    }
    else{
        struct Node *p;
        p=head->next;
        printf("\n%d is deleted",head->data);
        free(head);
        head=p;
    }
}
void top()
{
    if(head==NULL)
    printf("\nstack is empty");
    else{
        printf("\n%d is at top\n",head->data);
    }
}
int main()
{
    int ch;
    while (1)
    {
        printf("\npush=1\npop=2\ntop=3\nexit=4\t");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
           push();
            break;
        case 2:
            pop();
            break;
        case 3:
            top();
            break;
        case 4:
            exit(0);
            break;
        default:
            printf("\nInvalid choice");
            break;
        }
    }
}