bool solve(Node *root, int min, int max)
{
    if (root == NULL)
    {
        return true;
    }
    if (root->data > min && root->data < max)
    {
        // for left:
        bool left = solve(root->left, min, root->data);

        // for right:
        bool right = solve(root->right, root->data, max);

        return left && right;
    }
    else
    {
        return false;
    }
}
bool isBST(Node *root)
{
    // Your code here
    bool ans = solve(root, INT_MIN, INT_MAX);
    return ans;
}