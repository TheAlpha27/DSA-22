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

Node *findPred(Node *root)
{
    Node *pred = root->left;
    while (pred->right != NULL && pred->right != root)
    {
        pred = pred->right;
    }
    return pred;
}

void morrisTraversalInorder(Node *root)
{
    Node *current = root;
    Node *pred = NULL;
    while (current != NULL)
    {
        if (current->left == NULL)
        {
            cout << current->data << " ";
            current = current->right;
        }
        else
        {
            pred = findPred(current);
            if (pred->right == NULL)
            {
                pred->right = current;
                current = current->left;
            }
            else
            {
                pred->right = NULL;
                cout << current->data << " ";
                current = current->right;
            }
        }
    }
}
void morrisTraversalPreOrder(Node *root)
{
    Node *current = root;
    Node *pred = NULL;
    while (current != NULL)
    {
        if (current->left == NULL)
        {
            cout << current->data << " ";
            current = current->right;
        }
        else
        {
            pred = findPred(current);
            if (pred->right == NULL)
            {
                cout << current->data << " ";
                pred->right = current;
                current = current->left;
            }
            else
            {
                pred->right = NULL;
                current = current->right;
            }
        }
    }
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
    morrisTraversalInorder(root);
    return 0;
}