#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node*next,*prev;
}*head;
void add_begining()
{
    struct Node*a=(struct Node*)malloc(sizeof(struct Node));
    printf("\nEnter the Value of the Node:\t");
    scanf("%d",&a->data);
    a->prev=NULL;
    if(head==NULL)
    {
        a->next=NULL;
        head = a;
    }
    else
    {
        a->next = head;
        head->prev = a;
        head = a;
    }
    printf("\nNode is successfully inserted at first place ");
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
void Add_last()
{
    struct Node* abc=(struct Node*)malloc(sizeof(struct Node));
    printf("\nEnter the value of the Node:\t");
    scanf("%d",&abc->data);
    abc->next=NULL;
    if(head==NULL)
    {
        abc->prev = NULL;
        head=abc;
    }
    else
    {
        struct Node*temp=head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=abc;
        abc->prev=temp;
    }
    printf("\nNode is inserted successfully at last place");

}
void anypos(int value, int pos){
int i, FLAG=1;
struct Node *newNode,*temp=head;
newNode=(struct Node*)malloc(sizeof(struct Node));
newNode->data=value;
if(head==NULL){
newNode->prev = NULL;
newNode->next = NULL;
head=newNode;
}
else{
for(i=0;i < pos-1;i++){
temp=temp->next;
	if(temp->next==NULL){
		FLAG=0;
        printf("%dDeepanjan",i);
		break;
}
}
if(FLAG==1){
	newNode->next=temp->next;
	temp->next->prev=newNode;
	temp->next=newNode;
	newNode->prev=temp;
    printf("Insert successful”");
}
else
	printf("Insert Unsuccesful");
}
}




int main()
{
    int ch,value,pos;
    while (1)
    {
        printf("\n*************\n");
        printf("\nAdd at first position = 1\n2 = Add at last position\n3 = Add at any Position\n8 = Display \n9 = Exit\nEnter your choice:\t");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            add_begining();
            break;
        case 8:
            display(head);
            break;
        case 2:
           // reverse(head);
           Add_last();
            break;
        case 3:
            printf("\nEnter the Vaue of the node: ");
            scanf("%d",&value);
            printf("\nEnter the position where you want to insert the node: ");
            scanf("%d",&pos);
            anypos(value, pos);
            break;
        case 9 :
             exit(0);
            break;
        default:
            printf("\nInvalid choice");
            break;
        }
        printf("\n*************\n");
    }
}