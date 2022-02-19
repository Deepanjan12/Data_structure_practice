// traverse a binary tree
#include <iostream>
    using namespace std;
struct Node
{
    int data;
    struct Node *right, *left;
    Node(int n)
    {
        data = n;
        right = NULL;
        left = NULL;
    }
};
Node *insert(struct Node *node, int info)
{
    if (node == NULL)
    {
        return new Node(info);
    }
    else if (info < node->data)
    {
        node->left = insert(node->left, info);
    }
    else if (info > node->data)
    {
        node->right = insert(node->right, info);
    }
    return node;
}
void traverse_postorder(struct Node *node)
{
    if (node == NULL)
    {
        return;
    }
    traverse_postorder(node->left);
    traverse_postorder(node->right);
    cout << node->data << " ";
}
void traverse_inorder(struct Node *node)
{
    if (node == NULL)
    {
        return;
    }
    traverse_inorder(node->left);
    cout << node->data << " ";
    traverse_inorder(node->right);
}
void traverse_preorder(struct Node *node)
{
    if (node == NULL)
    {
        return;
    }
    cout << node->data << " ";
    traverse_preorder(node->left);
    traverse_preorder(node->right);
}

int main()
{
    int ch, data;
    struct Node *root = NULL;
    while (1)
    {
        cout << "Press 0 to exit\n";
        cout << "Press 1 to insert a node\n";
        cout << "press 2 to traverse\n";
        cin >> ch;
        switch (ch)
        {
        case 0:
            exit(0);
            break;
        case 1:
            cout << "Enter the value: ";
            cin >> data;
            cout << "\n";
            root = insert(root, data);
            break;
        case 2:
            cout << "Inorder Traversal : ";
            traverse_inorder(root);
            cout << "\n";
            cout << "Preorder Traversal : ";
            traverse_preorder(root);
            cout << "\n";
            cout << "Postorder Traversal : ";
            traverse_postorder(root);
            cout << "\n";

        default:
            cout << "Wrong Choice!!\n";
        }
    }
    return 0;
}