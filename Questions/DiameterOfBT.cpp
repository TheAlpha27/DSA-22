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

int diameter(node *root) // TC = O(n^2)
{
    if (root == NULL)
    {
        return 0;
    }
    int first = diameter(root->left);
    int second = diameter(root->right);
    int third = heightOfBinaryTree(root->left) + heightOfBinaryTree(root->right) + 1;
    return max(first, max(second, third));
}

pair<int, int> diameterOptimized(node *root) // TC = O(n)
{
    if (root == NULL)
    {
        pair<int, int> p = make_pair(0, 0);
        return p;
    }
    pair<int, int> left = diameterOptimized(root->left);
    pair<int, int> right = diameterOptimized(root->right);

    int first = left.first;
    int second = right.first;
    int third = left.second + right.second + 1;

    pair<int, int> ans;
    ans.first = max(first, max(second, third));
    ans.second = max(left.second, right.second) + 1;
    return ans;
}

int main()
{
    node *root = NULL;
    root = buildTree(root);
    cout << endl
         << "Diameter of the tree: " << diameterOptimized(root).first;
    // cout << endl
    //      << "Height of Binary Tree is: " << heightOfBinaryTree(root);

    return 0;
}