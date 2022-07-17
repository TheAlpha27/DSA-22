#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

Node *buildTree(Node *root)
{
    int data;
    cout << "Enter data" << endl;
    cin >> data;
    if (data == -1)
    {
        return NULL;
    }
    root = new Node(data);
    cout << "Enter data left to " << data << endl;
    root->left = buildTree(root->left);
    cout << "Enter data right to " << data << endl;
    root->right = buildTree(root->right);
    return root;
}

void printInOrder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    printInOrder(root->left);
    cout << root->data << " ";
    printInOrder(root->right);
}

Node *flattenBT(Node *root)
{
    Node *current = root;
    Node *pred = NULL;
    while (current != NULL)
    {
        if (current->left)
        {
            pred = current->left;
            while (pred->right)
            {
                pred = pred->right;
            }
            pred->right = current->right;
            current->right = current->left;
            current->left = NULL;
        }
        current = current->right;
    }
    return root;
}

/*
            1
          /   \
         3     5
       /  \   /  \
      7   11 17  NULL
*/
// 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1

int main()
{
    Node *root = NULL;
    root = buildTree(root);
    Node *ans = flattenBT(root);
    printInOrder(ans);
    return 0;
}