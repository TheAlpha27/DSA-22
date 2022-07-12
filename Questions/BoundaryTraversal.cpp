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

void traverseLeft(node *root, vector<int> &ans)
{
    if ((root == NULL) || (root->left == NULL && root->right == NULL))
    {
        return;
    }
    ans.push_back(root->data);
    if (root->left)
    {
        traverseLeft(root->left, ans);
    }
    else
    {
        traverseLeft(root->right, ans);
    }
}

void traverseLeaf(node *root, vector<int> &ans)
{
    if (root == NULL)
    {
        return;
    }
    if (root->left == NULL && root->right == NULL)
    {
        ans.push_back(root->data);
    }
    traverseLeaf(root->left, ans);
    traverseLeaf(root->right, ans);
}

void traverseRight(node *root, vector<int> &ans)
{
    if ((root == NULL) || (root->left == NULL && root->right == NULL))
    {
        return;
    }
    if (root->right)
    {
        traverseRight(root->right, ans);
    }
    else
    {
        traverseRight(root->left, ans);
    }
    ans.push_back(root->data);
}

vector<int> boundary(node *root)
{
    vector<int> ans;

    if (root == NULL)
    {
        return ans;
    }
    if (root->left == NULL && root->right == NULL)
    {
        ans.push_back(root->data);
        return ans;
    }

    ans.push_back(root->data);

    traverseLeft(root->left, ans);

    traverseLeaf(root, ans);

    traverseRight(root->right, ans);

    return ans;
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
    node *root = NULL;
    root = buildTree(root);
    vector<int> ans = boundary(root);
    cout << endl
         << endl;
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;

    return 0;
}