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

pair<bool, int> sumTree(node *root)
{
    if (root == NULL)
    {
        pair<bool, int> p = make_pair(true, 0);
        return p;
    }
    if (root->left == NULL && root->right == NULL)
    {
        pair<bool, int> p = make_pair(true, root->data);
        return p;
    }
    pair<bool, int> leftP = sumTree(root->left);
    pair<bool, int> rightP = sumTree(root->right);

    bool left = leftP.first;
    bool right = rightP.first;
    bool sum = (leftP.second + rightP.second) == root->data;
    pair<bool, int> ans;
    if (left && right && sum)
    {
        ans.first = true;
        ans.second = leftP.second + rightP.second + root->data;
        return ans;
    }
    else
    {
        ans.first = false;
        ans.second = leftP.second + rightP.second + root->data;
        return ans;
    }
}

int main()
{
    node *root = NULL;
    root = buildTree(root);
    cout << "SumTree: " << sumTree(root).first << endl;
    return 0;
}