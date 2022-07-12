#include <bits/stdc++.h>
using namespace std;

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

vector<int> vertical(node *root)
{
    map<int, map<int, vector<int>>> nodes;
    queue<pair<node *, pair<int, int>>> q;
    vector<int> ans;
    if (root == NULL)
    {
        return ans;
    }
    q.push(make_pair(root, make_pair(0, 0)));
    while (!q.empty())
    {
        pair<node *, pair<int, int>> temp = q.front();
        q.pop();
        node *front = temp.first;
        int hd = temp.second.first;
        int level = temp.second.second;
        nodes[hd][level].push_back(front->data);
        if (front->left)
        {
            q.push(make_pair(front->left, make_pair(hd - 1, level + 1)));
        }
        if (front->right)
        {
            q.push(make_pair(front->right, make_pair(hd + 1, level + 1)));
        }
    }
    for (auto i : nodes)
    {
        for (auto j : i.second)
        {
            for (auto k : j.second)
            {
                ans.push_back(k);
            }
        }
    }
    return ans;
}

int main()
{
    node *root = NULL;
    root = buildTree(root);
    vector<int> ans = vertical(root);
    cout << endl
         << endl;
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;

    return 0;
}