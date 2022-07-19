//Giving runtime error

void flattenBST(TreeNode<int>* root, TreeNode<int>* &head){
        if(root == NULL){
            return;
        }
        flattenBST(root->right, head);
        root->right = head;
        if(head!= NULL){
            head->left = root;
        }
        head = root;
        flattenBST(root->left, head);
    }
    
    TreeNode<int>* mergeLL(TreeNode<int>* head1, TreeNode<int>* head2){
        TreeNode<int>* head = NULL;
        TreeNode<int>* tail = NULL;
        while(head1!=NULL && head2!=NULL){
            if(head1->data < head2->data){
                if(head == NULL){
                    head = head1;
                    tail = head1;
                    head1 = head1->right;
                }
                else{
                    tail->right = head1;
                    head1->left = tail;
                    tail = head1;
                    head1 = head1->right;
                }
            } 
            if(head1->data > head2->data){
                if(head == NULL){
                    head = head2;
                    tail = head2;
                    head2 = head2->right;
                }
                else{
                    tail->right = head2;
                    head2->left = tail;
                    tail = head2;
                    head2 = head2->right;
                }
            } 
        }
        while(head1!=NULL){
            tail->right = head1;
            head1->left = tail;
            tail = head1;
            head1 = head1->right;
        }
        while(head2!=NULL){
            tail->right = head2;
            head2->left = tail;
            tail = head2;
            head2 = head2->right;
        }
        return head;
    }
    
    int countNodes(TreeNode<int>* head){
        int count = 0;
        TreeNode<int>* temp = head;
        while(temp= NULL){
            temp = temp->left;
            count++;
        }
        return count;
    }
    
    TreeNode<int>* buildBST(TreeNode<int>* head, int n){
        if(n <= 0 || head == NULL){
            return NULL;
        }
        TreeNode<int>* left = buildBST(head, n/2);
        TreeNode<int>* root = head;
        root->left = left;
        head = head->right;
        root->right = buildBST(head, n-n/2-1);
        return root;
    }
    
    void inOrder(TreeNode<int>* root, vector<int> &in){
        if(root == NULL){
            return;
        }
        inOrder(root->left, in);
        in.push_back(root->data);
        inOrder(root->right, in);
    }
TreeNode<int> *mergeBST(TreeNode<int> *root1, TreeNode<int> *root2){
    // Write your code here.
    //Flattening BSTs to DLLs
       TreeNode<int>* head1 = NULL;
       TreeNode<int>* head2 = NULL;
       flattenBST(root1, head1);
       flattenBST(root2, head2);
       head1->left = NULL;
       head2->left = NULL;
       
       //Merge both LL into 1 sorted LL
       TreeNode<int>* head = mergeLL(head1, head2);
       
       //Convert sorted LL to BST
       int nodes = countNodes(head);
       TreeNode<int>* root = buildBST(head, nodes);
    return root;
}