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

void preOrderTraversal(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << " ";

    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}

void postOrderTraversal(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    cout << root->data << " ";
}

bool searchBST(Node *root, int key)
{
    if (root == NULL)
    {
        return false;
    }
    Node *temp = root;
    while (temp != NULL)
    {
        if (key > temp->data)
        {
            temp = temp->right;
        }
        else if (key < temp->data)
        {
            temp = temp->left;
        }
        else if (key == temp->data)
        {
            return true;
        }
    }
}

Node *minVal(Node *root)
{
    Node *temp = root;
    while (temp->left != NULL)
    {
        temp = temp->left;
    }
    return temp;
}

Node *maxVal(Node *root)
{
    Node *temp = root;
    while (temp->right != NULL)
    {
        temp = temp->right;
    }
    return temp;
}

Node *deleteFromBST(Node *&root, int key)
{
    if (root == NULL)
    {
        return root;
    }
    if (key == root->data)
    {
        if (root->left == NULL && root->right == NULL)
        {
            delete (root);
            return NULL;
        }
        if (root->left != NULL && root->right == NULL)
        {
            Node *temp = root->left;
            delete (root);
            return temp;
        }
        if (root->right != NULL && root->left == NULL)
        {
            Node *temp = root->right;
            delete (root);
            return temp;
        }
        if (root->right && root->left)
        {
            int minData = minVal(root)->data;
            root->data = minData;
            root->right = deleteFromBST(root->right, minData);
            return root;
        }
    }
    else if (key > root->data)
    {
        root->right = deleteFromBST(root->right, key);
        return root;
    }
    else
    {
        root->left = deleteFromBST(root->left, key);
        return root;
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
    levelOrderTraversal(root);
    cout << endl
         << "PreOder:" << endl;
    preOrderTraversal(root);
    cout << endl
         << "PostOrder:" << endl;
    postOrderTraversal(root);
    cout << endl
         << "InOrder:" << endl;
    inOrderTraversal(root);
    cout << endl;

    root = insertIntoBST(root, 20);
    levelOrderTraversal(root);
    cout << endl
         << "PreOder:" << endl;
    preOrderTraversal(root);
    cout << endl
         << "PostOrder:" << endl;
    postOrderTraversal(root);
    cout << endl
         << "InOrder:" << endl;
    inOrderTraversal(root);
    cout << endl;

    if (searchBST(root, 100))
    {
        cout << "100 found" << endl;
    }
    else
    {
        cout << "100 not found" << endl;
    }

    root = deleteFromBST(root, 95);
    levelOrderTraversal(root);
    cout << endl
         << "PreOder:" << endl;
    preOrderTraversal(root);
    cout << endl
         << "PostOrder:" << endl;
    postOrderTraversal(root);
    cout << endl
         << "InOrder:" << endl;
    inOrderTraversal(root);
    cout << endl;

    return 0;
}