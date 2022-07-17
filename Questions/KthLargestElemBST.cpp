void inOrder(Node *root, vector<int> &ans)
{
    if (root == NULL)
    {
        return;
    }
    inOrder(root->left, ans);
    ans.push_back(root->data);
    inOrder(root->right, ans);
}
int kthLargest(Node *root, int K)
{
    // Your code here
    vector<int> ans;
    inOrder(root, ans);
    int n = ans.size();
    return ans[n - K];
}