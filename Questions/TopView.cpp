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

vector<int> topView(node *root)
{
    map<int, int> nodes;
    vector<int> ans;
    if (root == NULL)
    {
        return ans;
    }
    queue<pair<node *, int>> q;
    q.push(make_pair(root, 0));
    while (!q.empty())
    {
        pair<node *, int> temp = q.front();
        q.pop();
        node *front = temp.first;
        int hd = temp.second;
        if (nodes.find(hd) == nodes.end())
        { // to find if any value exists corresponding to the key value hd.
            nodes[hd] = front->data;
        }
        if (front->left)
        {
            q.push(make_pair(front->left, hd - 1));
        }
        if (front->right)
        {
            q.push(make_pair(front->right, hd + 1));
        }
    }
    for(auto i: nodes){
        ans.push_back(i.second);
    }
    return ans;
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
    node *root = NULL;
    root = buildTree(root);
    vector<int> ans = topView(root);
    cout << endl
         << endl;
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;

    return 0;
}