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

Node *solve(Node *root, int &k, int n)
{
    if (root == NULL)
    {
        return NULL;
    }
    if (root->data == n)
    {
        return root;
    }
    Node *leftAns = solve(root->left, k, n);
    Node *rightAns = solve(root->right, k, n);

    if (leftAns != NULL && rightAns == NULL)
    {
        k--;
        if (k <= 0)
        {
            k = INT_MAX; // if by chance k is less than zero so we set int max value to it so that its value becomes very large and it always keep returning the current node which is the answer
            return root;
        }
        return leftAns;
    }
    else if (leftAns == NULL && rightAns != NULL)
    {
        k--;
        if (k <= 0)
        {
            k = INT_MAX; // if by chance k is less than zero so we set int max value to it so that its value becomes very large and it always keep returning the current node which is the answer
            return root;
        }
        return rightAns;
    }
    else
    {
        return NULL;
    }
}

int kthAncestor(Node *root, int &k, int n)
{
    Node *ans = solve(root, k, n);
    if (ans == NULL || ans->data == n) // the edge case in which root nodes data == n, k value is between 1-100 so we will have to traverse above atleast once for the ancestor but the root node has no node above itself so we have to return -1 for that.
    {
        return -1;
    }
    else
    {
        return ans->data;
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
    int k;
    int n;
    cout << "Enter value of k" << endl;
    cin >> k;
    cout << "Enter the value of node" << endl;
    cin >> n;
    int ans = kthAncestor(root, k, n);
    cout << ans << endl;
    return 0;
}