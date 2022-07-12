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

int heightOfBinaryTree(node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int h1 = heightOfBinaryTree(root->left);
    int h2 = heightOfBinaryTree(root->right);
    return max(h1, h2) + 1;
}

bool checkBalancedTree(node *root) // TC = O(n^2)
{
    if (root == NULL)
    {
        return true;
    }
    bool left = checkBalancedTree(root->left);
    bool right = checkBalancedTree(root->right);
    bool diff = abs(heightOfBinaryTree(root->left)-heightOfBinaryTree(root->right))<=1;

    if(left && right && diff){
        return true;
    }
    else{
        return false;
    }
}

pair<bool, int> checkBalancedTreeOptimized(node* root){// TC: O(n)
    if(root == NULL){
        pair<bool, int> p = make_pair(true, 0);
        return p;
    }
    pair<bool, int> left = checkBalancedTreeOptimized(root->left);
    pair<bool, int> right = checkBalancedTreeOptimized(root->right);

    bool diff = abs(left.second - right.second)<=1;
    pair<bool, int> ans;
    if(left.first && right.first && diff){
        ans.first = true;
        ans.second = max(left.second, right.second)+1;
        return ans;
    }
    else{
        ans.first = false;
        ans.second = max(left.second, right.second)+1;
        return ans;
    }

}

int main()
{
    node *root = NULL;
    root = buildTree(root);
    // cout << endl
    //      << "Height of Binary Tree is: " << heightOfBinaryTree(root);

    cout<<"Balanced: "<<checkBalancedTreeOptimized(root).first<<endl;

    return 0;
}