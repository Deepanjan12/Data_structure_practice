#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
} *front = NULL,*rear = NULL;
void enqueue()
{
    // 1 2 3 4 5   h=1
    // 7-> 1-> 2-> 3-> 4-> 5->
    // 1->2->3......
    struct Node *a = (struct Node *)malloc(sizeof(struct Node));
    printf("\nEnter the value to push: ");
    scanf("%d", &a->data);
    a->next = NULL;
    if (front == NULL)
    {
        front = a;
        rear = a;
        return;
    }
    else
    {
        a->next = rear;
        rear = a;
    }
}
 // 1-> 2-> 3-> 4-> 5->
void dequeue()
{
    if (front== NULL)
    {
        printf("\nNo element in stack. Pop is not possible");
    }
    else
    {
        struct Node *p;
        p = front->next;
        printf("\n%d is deleted", front->data);
        free(front);
        front= p;
    }
}
void display()
{
    if(rear==NULL)
    {
        printf("\nQueue is empty");
        return;
    }
    else
    {

        struct Node *p=rear;
        while (p!=NULL){
            printf("%d\t", p->data);
            p = p->next;
        }

    }
}
int main()
{
    int ch;
    while (1)
    {
        printf("\nenqueue=1\ndequeue=2\ndisplay=3\nexit=4\t");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            enqueue();
            break;
        case 2:
            dequeue();
            break;
        case 3:
            display();
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