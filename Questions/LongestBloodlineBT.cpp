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

void calculate(node *root, int length, int &maxLength, int sum, int &maxSum)
{
    if (root == NULL)
    {
        return;
    }
    length++;
    sum = sum + root->data;
    if (length >= maxLength)
    {
        if (length == maxLength)
        {
            maxSum = max(sum, maxSum);
            maxLength = length;
        }
        else
        {
            maxSum = sum;
            maxLength = length;
        }
    }
    if (root->left)
    {
        calculate(root->left, length, maxLength, sum, maxSum);
    }
    if (root->right)
    {
        calculate(root->right, length, maxLength, sum, maxSum);
    }
}

int longestBloodline(node *root)
{
    int length = 0;
    int maxLength = 0;
    int sum = 0;
    int maxSum = INT_MIN;

    calculate(root, length, maxLength, sum, maxSum);
    return maxSum;
}

int main()
{
    node *root = NULL;
    root = buildTree(root);
    int ans = longestBloodline(root);
    cout << ans << endl;
    return 0;
}