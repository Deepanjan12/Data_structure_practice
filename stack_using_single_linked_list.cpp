//stack using linked list
#include<stdio.h>
#include<stdlib.h>
struct Node{
	int data;
	struct Node *next;
}*top=NULL;
void push()
{
	struct Node *newNode=(struct Node*)malloc(sizeof(struct Node));
	printf("\nEnter the data: ");
	scanf("%d",&newNode->data);
    if (top == NULL)
    {
		newNode->next=NULL;
	}
	else
	{
		newNode->next=top;
    }
    top =newNode;
	printf("\nPush is successfull");
}
void display()
{
	if(top==NULL)
	{
		printf("\nStack is empty");
	}
	else
	{
		Node *temp=top;
		while(temp->next!=NULL)
		{
			printf("%d->\t",temp->data);
			temp=temp->next;
		}
        printf("%d->NULL",temp->data);
	}
}
void pop()
{
	if(top==NULL)
	{
		printf("\nStack is empty");
	}
	else
	{
		Node *temp=top;
		top=top->next;
        printf("%d is poped\n pop is successfull",temp->data);
		free(temp);

	}
}
int main()
{
	int ch;
    while(1)
    {
        printf("\n1. Push\n2. Pop\n3. Display\n4. Exit");
        printf("\nMake choice: ");
        scanf("%d",&ch);
        switch (ch)
        {
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            display();
            break;
        case 4:
            exit(0);
        default:
            printf("\nWrong Choice");
        }
    }

}