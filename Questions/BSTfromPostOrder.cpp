Node* buildTree(int min, int max, int post[], int size, int &index){
    if(index < 0){
        return NULL;
    }
    if(post[index] <min || post[index] > max){
        return NULL;
    }
    Node* root = new Node(post[index--]);
    root->right = buildTree(root->data, max, post, size, index);
    root->left = buildTree(min, root->data, post, size, index);
    
    return root;
}

Node *constructTree (int post[], int size)
{
//code here
    int min = INT_MIN;
    int max = INT_MAX;
    int index = size-1;
    Node* root = buildTree(min, max, post, size, index);
    return root;
}