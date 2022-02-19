/*
     Menu driven C program to implement
     1. insert a node at the beginning
     2. insert a node at the end
     3. joseph problem
     4. display the list
     5. exit

*/

#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};
struct Linked_List
{
    struct Node *head, *tail;
};
void create(struct Linked_List *l1)
{

    struct Node *abc = (struct Node *)malloc(sizeof(struct Node));
    printf("Enter Data:\n");
    scanf("%d", &abc->data);
    if (l1->head == NULL)
    {
        l1->head = abc;
        l1->tail = abc;
        l1->tail->next = l1->head;
    }
    else
    {
        l1->tail->next = abc;
        abc->next = l1->head;
    }
}
void insert_at_head(struct Linked_List *l1)
{
    create(l1);
    l1->head = l1->tail->next;
}
void insert_at_tail(struct Linked_List *l1)
{
    create(l1);
    l1->tail = l1->tail->next;
}
void joseph(struct Linked_List *list)
{
    int count;
    printf("\nEnter count:\t");
    scanf("%d", &count);
    if (count < 2)
    {
        printf("\nInvalid Count");
        return;
    }
    struct Node *l1 = list->head;
    struct Node *temp;
    int k = 1;
    do
    {
        if (k == count - 1)
        {
            temp = l1->next;
            printf("\nDeleted Node= %d", temp->data);
            l1->next = l1->next->next;
            l1 = l1->next;
            free(temp);
            k = 1;
        }
        else
        {
            l1 = l1->next;
            k++;
        }
    } while (l1->next != l1);

    printf("\nThief= %d", l1->data);
    list->head = l1;
}
void display(struct Linked_List *l1)
{
    struct Node *p = l1->head;
    printf("\n");
    if (l1->head == NULL)
    {
        printf("\nEmpty Linked List");
        return;
    }
    else
    {
        printf("Elements are:\n");
        while (p != l1->tail)
        {
            printf("%d ", p->data);
            p = p->next;
        }
        printf("%d ", p->data);
    }
}
int main()
{
    struct Linked_List l1;
    l1.head = NULL;
    l1.tail = NULL;
    int ch;
    do
    {
        printf("\n0.Exit\n1.Insert at Head\n2.Insert at Tail\n3.Joseph Problem\n4.Display\n5.Exit\n");
        printf("\nEnter your choice:\t");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            insert_at_head(&l1);
            break;
        case 2:
            insert_at_tail(&l1);
            break;
        case 3:
            joseph(&l1);
            break;
        case 4:
            display(&l1);
            break;
        case 5:
            break;
        default:
            printf("\nInvalid Choice");
        }
    } while (ch != 5);
    return 0;
}