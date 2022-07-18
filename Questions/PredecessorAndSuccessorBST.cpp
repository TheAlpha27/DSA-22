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

Node *insertIntoBST(Node *root, int data)
{
    if (root == NULL)
    {
        root = new Node(data);
        return root;
    }
    if (data > root->data)
    {
        root->right = insertIntoBST(root->right, data);
    }
    if (data < root->data)
    {
        root->left = insertIntoBST(root->left, data);
    }
    return root;
}

void takeInput(Node *&root)
{
    int data;
    cout << "Enter data" << endl;
    cin >> data;
    while (data != -1)
    {
        cout << "Enter data" << endl;
        root = insertIntoBST(root, data);
        cin >> data;
    }
}

void levelOrderTraversal(Node *root)
{
    cout << endl
         << "Level Order Traversal: " << endl;
    queue<Node *> q;
    Node *temp;
    q.push(root);
    q.push(NULL);
    while (!q.empty())
    {
        temp = q.front();
        q.pop();
        if (temp == NULL)
        {
            cout << endl;
            if (!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            cout << temp->data << " ";
            if (temp->left)
            {
                q.push(temp->left);
            }
            if (temp->right)
            {
                q.push(temp->right);
            }
        }
    }
}

void inOrderTraversal(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    inOrderTraversal(root->left);
    cout << root->data << " ";
    inOrderTraversal(root->right);
}

void inOrder(Node *root, vector<Node *> &in)
{
    if (root == NULL)
    {
        return;
    }
    inOrder(root->left, in);
    in.push_back(root);
    inOrder(root->right, in);
}

void findPreSuc(Node *root, Node *&pre, Node *&suc, int key)
{

    // Your code goes here
    vector<Node *> in;
    inOrder(root, in);
    for (int i = 0; i < in.size(); i++)
    {
        if (in[i]->data == key)
        {
            pre = in[i - 1];
            suc = in[i + 1];
        }
    }
}

/*
            100
          /     \
        90      110
      /   \        \
     60   95       120
         /        /   \
        92      115    125

    100 90 60 95 92 110 120 115 125 -1
*/

int main()
{
    Node *root = NULL;
    takeInput(root);
    cout << "LevelOrder:" << endl;
    levelOrderTraversal(root);
    cout << "InOrder:" << endl;
    inOrderTraversal(root);
    cout << endl;
    int key;
    cout << "Enter target: " << endl;
    cin >> key;
    Node *pre = NULL;
    Node *suc = NULL;
    findPreSuc(root, pre, suc, key);
    cout << "Pre: " << pre->data << " Suc: " << suc->data << endl;
    return 0;
}