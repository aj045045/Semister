/*
    33) Write a program to implement binary tree using link list and traverse the tree in PreOrder, PostOrder and InOrder(Use Recursion).
    39) Write a program to implement Binary search tree / ordered binary tree.
*/

#include <iostream>
#include <stdlib.h>
using namespace std;

struct tree {
    int value;
    struct tree* left;
    struct tree* right;
};

void inorderTraversal(struct tree* root)
{
    if (root == NULL)
        return;
    else
    {
        inorderTraversal(root->left);
        cout << root->value << "-> ";
        inorderTraversal(root->right);
    }
}

void preorderTraversal(struct tree* root)
{
    if (root == NULL)
        return;
    else
    {
        cout << root->value << "-> ";
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
}

void postorderTraversal(struct tree* root)
{
    if (root == NULL)
        return;
    else
    {
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        cout << root->value << "-> ";
    }
}

struct tree* createRootNode(int value) {
    struct tree* temp;
    temp = (struct tree*)malloc(sizeof(struct tree));
    temp->value = value;
    temp->left = temp->right = NULL;
    return temp;
}

struct tree* insertLeft(struct tree* root, int value)
{
    root->left = createRootNode(value);
    return root->left;
}

struct tree* insertRight(struct tree* root, int value)
{
    root->right = createRootNode(value);
    return root->right;
}

void insertTreeNode(struct tree* root, int value)
{
    if (value > root->value)
    {
        if (root->right != NULL)
            insertTreeNode(root->right, value);
        else
            insertRight(root, value);
    }
    else {
        if (root->left != NULL)
            insertTreeNode(root->left, value);
        else
            insertLeft(root, value);
    }
}

int main()
{
    int choice = 1, value;
    cout << "Enter the root Node value :";
    cin >> value;
    struct tree* root = createRootNode(value);
    while (choice == 1)
    {
        cout << "\nEnter value to insert in the tree :";
        cin >> value;
        insertTreeNode(root, value);
        cout << "Do you want to add new record YES[1] and NO[0] :";
        cin >> choice;
    }

    cout << "\n\nPre-order traversal" << endl;
    preorderTraversal(root);

    cout << "\n\nIn-order traversal" << endl;
    inorderTraversal(root);

    cout << "\n\nPost-order traversal" << endl;
    postorderTraversal(root);
    cout << endl;
}