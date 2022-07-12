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

vector<int> zigzag(node *root)
{
    vector<int> ans;
    if (root == NULL)
    {
        return ans;
    }
    queue<node *> q;
    q.push(root);
    bool leftToRight = true;
    while (!q.empty())
    {
        int size = q.size();
        vector<int> temp(size);
        // process levels
        for (int i = 0; i < size; i++)
        {
            node *frontNode = q.front();
            q.pop();
            int index = leftToRight ? i : size - i - 1;
            temp[index] = frontNode->data;
            if (frontNode->left != NULL)
            {
                q.push(frontNode->left);
            }
            if (frontNode->right != NULL)
            {
                q.push(frontNode->right);
            }
        }
        leftToRight = !leftToRight;
        for (auto i : temp)
        {
            ans.push_back(i);
        }
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
// 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1

int main()
{
    node *root = NULL;
    root = buildTree(root);
    vector<int> ans = zigzag(root);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;

    return 0;
}