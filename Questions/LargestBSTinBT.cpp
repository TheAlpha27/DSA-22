#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int d)
    {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

Node *buildTree(Node *root)
{
    cout << "Enter the data: " << endl;
    int data;
    cin >> data;
    root = new Node(data);

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

class Info
{
public:
    int size;
    int mx;
    int mn;
    int ans;
    bool isBST;
};
Info largestBstInBT(Node *root)
{
    if (root == NULL)
    {
        return {0, INT32_MIN, INT32_MAX, 0, true};
    }
    if (root->left == NULL && root->right == NULL)
    {
        return {1, root->data, root->data, 1, true};
    }

    Info leftInfo = largestBstInBT(root->left);
    Info rightInfo = largestBstInBT(root->right);

    Info curr;
    curr.size = (1 + leftInfo.size + rightInfo.size);

    if (leftInfo.isBST && rightInfo.isBST && leftInfo.mx < root->data && rightInfo.mn > root->data)
    {
        curr.mn = min(leftInfo.mn, min(rightInfo.mn, root->data));
        curr.mx = max(rightInfo.mx, max(leftInfo.mx, root->data));
        curr.ans = curr.size;
        curr.isBST = true;
        return curr;
    }
    curr.ans = max(leftInfo.ans, rightInfo.ans);
    curr.isBST = false;
    return curr;
}
int largestBST(Node *root)
{
    // Your code here
    Info temp = largestBstInBT(root);
    return temp.ans;
}

/*
            10
          /   \
         7     5
       /  \   /  \
      5   9 17  NULL
*/
// 10 7 5 -1 -1 9 -1 -1 5 17 -1 -1 -1

int main()
{
    Node *root = NULL;
    root = buildTree(root);
    int ans = largestBST(root);
    cout << "Largest size of bst is: " << ans << endl;
    return 0;
}