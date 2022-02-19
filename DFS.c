#include <stdio.h>
#include <stdlib.h>
struct edgelist;
typedef struct nodelist
{
    int info;
    struct nodelist *next;
    struct edgelist *adj;
    int flag;
} Node;
typedef struct edgelist
{
    struct nodelist *dest;
    struct edgelist *link;
} edge;
typedef struct stacklist
{
    Node *vertex;
    struct nodelist *forw;
} stack;
Node *start;
stack *top;
int n;
void push(Node *);
void BuidNodeList()
{
    Node *curr, *prev;
    int i;
    printf("\nEnter the number of nodes in a graph:");
    scanf("%d", &n);
    prev = NULL;
    for (i = 1; i < n; i++)
    {
        curr = (Node *)malloc(sizeof(Node));
        if (curr == NULL)
        {
            printf("\nOut of memory space");
            exit(0);
        }
        curr->next = NULL;
        curr->adj = NULL;
        curr->info = i;
        curr->flag = 1;
        if (prev == NULL)
            start = curr;
        else
            prev->next = curr;
        prev = curr;
    }
}
void insertEdges()
{
    edge *curr, *prev;
    Node *temp, *ptr;
    int i, j, m, k, p;
    temp = start;
    for (i = 1; j <= n; j++)
    {
        printf("\n Enter the adjacent node of %d :", i);
        scanf("%d", &m);
        prev = NULL;
        for (j = 1; j <= m; j++)
        {
            printf("\nEnter the %d adjacent node of %d: ", j, i);
            scanf("%d", &k);
            curr = (edge *)malloc(sizeof(edge));
            if (curr == NULL)
            {
                printf("\nOut of memory space\n");
                exit(0);
            }
            ptr = start;
            curr->link = NULL;
            p = 1;
            while (p < k)
            {
                ptr = ptr->next;
                p++;
            }
            curr->dest = ptr;
            if (prev == NULL)
            {
                temp->adj = curr;
            }
            else
                prev->link = curr;
            prev = curr;
        }
        temp = temp->next;
    }
}
void display()
{
    Node *node;
    edge *ptr;
    node = start;
    printf("\nNode\tAdjacency list\n");
    printf("--\t------\n");
    while (node != NULL)
    {
        printf("%d", node->info);
        ptr = node->adj;
        printf("\t");
        while (ptr != NULL)
        {
            printf("%d    ", ptr->dest->info);
            ptr = ptr->link;
        }
        printf("\n");
        node = node->next;
    }
}
void push(Node *x)
{
    stack *temp;
    temp = (stack *)malloc(sizeof(stack));
    if (temp == NULL)
    {
        printf("\nOut of memory space");
        exit(0);
    }
    x->flag = 2;
    temp->vertex = x;
    temp->forw = NULL;
    if (top == NULL)
        top = temp;
    else
    {
        temp->forw = top;
    }
    top = temp;
}
Node *pop()
{
    Node *temp;
    stack *ptr;
    temp = top->vertex;
    ptr = top;
    top = top->forw;
    temp->flag = 3;
    free(ptr);
    return temp;
}
int main()
{
    Node *ptr, *temp;
    edge *ege;
    BuidNodeList();
    insertEdges();
    display();
    top = NULL;
    printf("\nDFS traversal\n");
    ptr = start;
    push(ptr);
    do
    {
        if (top != NULL)
        {
            temp = pop();
            printf("%d        ", temp->info);
        }
        ege = temp->adj;
        while (ege != NULL)
        {
            if (ege->dest->flag == 1)
                push(ege->dest);
        }
        ege = ege->link;
    } while (top != NULL);
}