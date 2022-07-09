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
    cout << "Enter data:" << endl;
    int data;
    cin >> data;
    if (data == -1)
    {
        return NULL;
    }
    root = new node(data);

    cout << "Enter data left to " << root->data << endl;
    root->left = buildTree(root->left);
    cout << "Enter data right to " << root->data << endl;
    root->right = buildTree(root->right);

    return root;
}

void countLeaf(node *root, int &count)
{
    if (root == NULL)
    {
        return;
    }
    countLeaf(root->left, count);
    if (root->left == NULL && root->right == NULL)
    {
        count++;
    }
    countLeaf(root->right, count);
}

int main()
{
    node *root = NULL;
    root = buildTree(root);
    int count = 0;
    countLeaf(root, count);
    cout << "Number of leaf nodes are " << count << endl;
    return 0;
}