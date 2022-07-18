void inOrder(Node* root, vector<int> &in){
    if(root == NULL){
        return;
    }
    inOrder(root->left, in);
    in.push_back(root->data);
    inOrder(root->right, in);
}
Node* solve(vector<int> in, int start, int end){
    if(start>end){
        return NULL;
    }
    int mid = (start+end)/2;
    Node* root = new Node(in[mid]);
    root->left = solve(in, start, mid-1);
    root->right = solve(in, mid+1, end);
    return root;
}
Node* buildBalancedTree(Node* root)
{
	// Code here
	vector<int> in;
	inOrder(root, in);
	int start = 0;
	int end = in.size()-1;
	Node* ans = solve(in, start, end);
	return ans;
}