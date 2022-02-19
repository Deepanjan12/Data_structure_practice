//BST
#include<stdio.h>
#include<stdlib.h>
struct Node
{
	int data;
	struct Node *right_child,*left_child;
}*root=	NULL;
struct Node *newnode( int data)
{
	struct Node *temp=(struct Node*)malloc(sizeof(struct Node));
	temp->data=data;
	temp->left_child=NULL;
	temp->right_child=NULL;
}
struct Node *insert(struct Node *node, int data)
{
	if(root=NULL)
	{
		return newnode(data);
	}

	if(node->data<data)
	{
		node->right_child= insert(node->right_child, data);
	}
	else
	{
		node->left_child= insert(node->left_child,data);
	}
	return node;
}
void inorder( struct Node *t)
{
	if(t!=NULL)
	{
		inorder(t->left_child);
		printf("%d ",t->data);
		inorder(t->right_child);
	}
}
void preorder(struct Node *t)
{
	if(t!=NULL)
	{
		printf("%d ",t->data);
		preorder(t->left_child);
		preorder(t->right_child);
	}
}
void postorder(struct Node *t)
{
	if(t!=NULL)
	{
		postorder(t->left_child);
		postorder(t->right_child);
		printf("%d ",t->data);
	}
}
struct Node *search(int data)
{
	struct Node *current = root;
	printf("\nVisiting elements:");
	while(current->data!=data)
	{
		if(current!=NULL)
		{
			printf("%d",current->data);
		}
		if(current->data>data)
		{
			current=current->left_child;
		}
		else
		{
			current=current->right_child;
		}
		if(current=NULL)
			return NULL;
		return current;
	}
}
int main()
{
	int data,sd,ch;
	while(1)
	{
		printf("\n Press 1 to insert Node");
		printf("\n Press 2 to search Node");
		printf("\n Press 3 to traverse");
		printf("\n Press 4 to exit");
		printf("\nMake your choice: ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				printf("\nEnter the value of the node want to insert: ");
				scanf("%d",&data);
				insert(root,data);
				break;
			case 2:
				printf("\nEnter the data want to search: ");
				scanf("%d",&sd);
				printf("\nValue is found %d",search(sd));
				break;
			case 3:
				printf("\nInorder Traversal:\n");
				inorder(root);
				printf("\nPreorder Traversal:\n");
				preorder(root);
				printf("\nPreorder Traversal:\n");
				postorder(root);
				break;
			case 4:
				exit(0);
				default:
					printf("\nWrong Choice: ");
		}
	}
}
