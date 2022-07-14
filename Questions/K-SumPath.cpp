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

void solve(Node *root, int k, vector<int> path, int &count)
{
    if (root == NULL)
    {
        return;
    }
    path.push_back(root->data);
    solve(root->left, k, path, count);
    solve(root->right, k, path, count);
    int sum = 0;
    for (int i = path.size() - 1; i >= 0; i--)
    {
        sum = sum + path[i];
        if (sum == k)
        {
            count++;
        }
    }
    path.pop_back();
}

int kSumPath(Node *root, int k)
{
    vector<int> path;
    int count = 0;
    solve(root, k, path, count);
    return count;
}
/*
            1
          /   \
         3     2
       /  \   /  \
      2   1 1     4

      1 3 2 -1 -1 1 -1 -1 2 1 -1 -1 4 -1 -1
*/
int main()
{
    Node *root = NULL;
    root = buildTree(root);
    int k;
    cout << "Enter value of k" << endl;
    cin >> k;
    int ans = kSumPath(root, k);
    cout << ans << endl;
    return 0;
}