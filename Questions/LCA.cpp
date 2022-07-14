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

Node *LCA(Node *root, int n1, int n2)
{
    if (root == NULL)
    {
        return NULL;
    }
    if (root->data == n1 || root->data == n2)
    {
        return root;
    }
    Node *leftAns = LCA(root->left, n1, n2);
    Node *rightAns = LCA(root->right, n1, n2);
    if (leftAns != NULL && rightAns != NULL)
    {
        return root;
    }
    else if (leftAns == NULL && rightAns != NULL)
    {
        return rightAns;
    }
    else if (leftAns != NULL && rightAns == NULL)
    {
        return leftAns;
    }
    else
    {
        return NULL;
    }
}
/*
            1
          /   \
         3     5
       /  \   /  \
      7   11 17  NULL
*/
int main()
{
    Node *root = NULL;
    root = buildTree(root);
    int n1;
    int n2;
    cout << "Enter values of n1 and n2" << endl;
    cin >> n1;
    cin >> n2;
    Node *ans = LCA(root, n1, n2);
    cout << ans->data << endl;
    return 0;
}