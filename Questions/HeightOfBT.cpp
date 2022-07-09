#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node *left;
    node *right;
    node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

node *buildTree(node *root)
{
    int data;
    cout << "Enter data";
    cin >> data;
    if (data == -1)
    {
        return NULL;
    }
    root = new node(data);
    cout << "Enter data left to " << data << endl;
    root->left = buildTree(root->left);
    cout << "Enter data right to " << data << endl;
    root->right = buildTree(root->right);
    return root;
}

int heightOfBinaryTree(node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int h1 = heightOfBinaryTree(root->left);
    int h2 = heightOfBinaryTree(root->right);
    return max(h1, h2) + 1;
}

int main()
{
    node *root = NULL;
    root = buildTree(root);
    cout << endl
         << "Height of Binary Tree is: " << heightOfBinaryTree(root);

    return 0;
}