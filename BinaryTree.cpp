#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node *left;
    node *right;

    node(int d)
    {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

node *buildTree(node *root)
{
    cout << "Enter the data: " << endl;
    int data;
    cin >> data;
    root = new node(data);

    if (data == -1)
    {
        return NULL;
    }
    cout << "Enter data for inserting to the left of " << data << endl;
    root->left = buildTree(root->left);
    cout << "Enter data for inserting to the right of " << data << endl;
    root->right = buildTree(root->right);

    return root;
}

/*
            1
          /   \
         3     5
       /  \   /  \
      7   11 17  NULL
*/

void levelOrderTraversal(node *root)
{
    cout << endl
         << "Level Order Traversal: " << endl;
    queue<node *> q;
    node *temp;
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

void inOrderTraversal(node *root)
{
    if (root == NULL)
    {
        return;
    }
    inOrderTraversal(root->left);
    cout << root->data << " ";
    inOrderTraversal(root->right);
}

void preOrderTraversal(node *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << " ";

    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}

void postOrderTraversal(node *root)
{
    if (root == NULL)
    {
        return;
    }
    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    cout << root->data << " ";
}

void buildFromLevelOrder(node *&root)
{
    queue<node *> q;
    cout << "Enter data for root" << endl;
    int data;
    cin >> data;
    root = new node(data);
    q.push(root);

    while (!q.empty())
    {
        node *temp = q.front();
        q.pop();

        cout << "Enter left data for " << temp->data << endl;
        int leftData;
        cin >> leftData;
        if (leftData != -1)
        {
            temp->left = new node(leftData);
            q.push(temp->left);
        }
        cout << "Enter right data for " << temp->data << endl;
        int rightData;
        cin >> rightData;
        if (rightData != -1)
        {
            temp->right = new node(rightData);
            q.push(temp->right);
        }
    }
}

int main()
{
    node *root = NULL;
    buildFromLevelOrder(root);

    //1 3 5 7 11 17 -1 -1 -1 -1 -1 -1 -1

    // root = buildTree(root);

    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1

    levelOrderTraversal(root);
    // cout << endl
    //      << "In-Order Traversal: " << endl;
    // inOrderTraversal(root);
    // cout << endl
    //      << "Pre-Order Traversal: " << endl;
    // preOrderTraversal(root);
    // cout << endl
    //      << "Post-Order Traversal: " << endl;
    // postOrderTraversal(root);

    return 0;
}