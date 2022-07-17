void inOrder(Node* root, int &ans, int &K){
        if(root == NULL){
            return;
        }
        inOrder(root->left, ans, K);
        if(K != 0){
         K--;
         if(K == 0){
            ans = root->data;
            return;
        }
        }
        
        inOrder(root->right, ans, K);
    }
    int KthSmallestElement(Node *root, int K) {
        // add code here.
        int ans = -1;
        inOrder(root, ans, K);
        return ans;
    }