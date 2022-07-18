#include <vector>
void inOrder(TreeNode<int>* root, vector<int> &in)
{
    if(root == NULL){
        return;
    }
    inOrder(root->left, in);
    in.push_back(root->data);
    inOrder(root->right, in);
}
TreeNode<int>* flatten(TreeNode<int>* root)
{
    // Write your code here
    vector<int> in;
    inOrder(root, in);
    int size = in.size();
    TreeNode<int>* head = new TreeNode<int>(in[0]);
    TreeNode<int>* curr = head;
    for(int i = 1; i<size; i++){
        TreeNode<int>* temp = new TreeNode<int>(in[i]);
        curr->left = NULL;
        curr->right = temp;
        curr = temp;
    }
    curr->left = NULL;
    curr->right = NULL;
    return head;
}