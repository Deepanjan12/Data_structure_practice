//inorder traversal iterative
#include<bits/stdc++.h>
    using namespace std;
struct Node{
    int data;
    struct Node *right,*left;
    Node(int n){
        data=n;
        right=NULL;
        left=NULL;
    }
};
Node *insert(struct Node *node,int info)
{
   if(node == NULL)
   {
       return new Node(info);
   }
   else if(info < node->data)
   {
       node->left = insert(node->left,info);
   }
   else
   {
       node -> right = insert(node->right,info);
   }
    return node;
}

   void inOrder(struct Node *root)
{
    stack<Node *> s;
    Node *curr = root;

    while (curr != NULL || s.empty() == false)
    {

        while (curr !=  NULL)
        {
            s.push(curr);
            curr = curr->left;
        }
        curr = s.top();
        s.pop();

        cout << curr->data << " ";
        curr = curr->right;

    }
}

int main()
{
    int ch,data;
    struct Node *root = NULL;
    while(1)
    {
        cout<<"\nPress 0 to exit";
        cout<<"\npress 1 to insert";
        cout<<"\npress 2 to traverse";
        cout<<"\nMake your choice : ";
        cin>>ch;
        switch(ch)
        {
            case 0:
                exit(0);
                break;
            case 1:
                cout<<"Enter the value: ";
                cin>>data;
                root=insert(root,data);
                break;
            case 2:
                inOrder(root);
                break;
            default:
                cout<<"Wrong choice!!";
        }
    }
    return 0;
}