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

// create mapping
// return target node
Node *createParentMapping(Node *root, int target, map<Node *, Node *> &nodeToParent)
{
    Node *res = NULL;
    queue<Node *> q;
    q.push(root);
    nodeToParent[root] = NULL;
    while (!q.empty())
    {
        Node *front = q.front();
        q.pop();
        if (front->data == target)
        {
            res = front;
        }
        if (front->left)
        {
            nodeToParent[front->left] = front;
            q.push(front->left);
        }
        if (front->right)
        {
            nodeToParent[front->right] = front;
            q.push(front->right);
        }
    }
    return res;
}

int burnTree(Node *targetNode, map<Node *, Node *> nodeToParent)
{
    map<Node *, bool> visited;
    queue<Node *> q;
    q.push(targetNode);
    visited[targetNode] = 1;
    int time = 0;
    while (!q.empty())
    {
        bool flag = 0;
        int size = q.size();
        for (int i = 0; i < size; i++)
        {
            Node *front = q.front();
            q.pop();
            if (front->left && !visited[front->left])
            {
                flag = 1;
                q.push(front->left);
                visited[front->left] = 1;
            }
            if (front->right && !visited[front->right])
            {
                flag = 1;
                q.push(front->right);
                visited[front->right] = 1;
            }
            if (nodeToParent[front] && !visited[nodeToParent[front]])
            {
                flag = 1;
                q.push(nodeToParent[front]);
                visited[nodeToParent[front]] = 1;
            }
        }
        if (flag == 1)
        {
            time++;
        }
    }
    return time;
}

int minTime(Node *root, int target)
{
    map<Node *, Node *> nodeToParent;
    Node *targetNode = createParentMapping(root, target, nodeToParent);
    int ans = burnTree(targetNode, nodeToParent);
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
    Node *root = NULL;
    root = buildTree(root);
    int target;
    cout << "Enter target node" << endl;
    cin >> target;
    int ans = minTime(root, target);
    cout << ans << endl;
    return 0;
}