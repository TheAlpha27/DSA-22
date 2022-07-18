#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

Node *insertIntoBST(Node *root, int data)
{
    if (root == NULL)
    {
        root = new Node(data);
        return root;
    }
    if (data > root->data)
    {
        root->right = insertIntoBST(root->right, data);
    }
    if (data < root->data)
    {
        root->left = insertIntoBST(root->left, data);
    }
    return root;
}

void takeInput(Node *&root)
{
    int data;
    cout << "Enter data" << endl;
    cin >> data;
    while (data != -1)
    {
        cout << "Enter data" << endl;
        root = insertIntoBST(root, data);
        cin >> data;
    }
}

void levelOrderTraversal(Node *root)
{
    cout << endl
         << "Level Order Traversal: " << endl;
    queue<Node *> q;
    Node *temp;
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

void inOrder(Node* root, vector<int> &in){
    if(root == NULL){
        return;
    }
    inOrder(root->left, in);
    in.push_back(root->data);
    inOrder(root->right, in);
}

bool twoSumInBST(Node* root, int target) {
	//Write your code here
    vector<int> in;
    inOrder(root, in);
    
    int start = 0;
    int end = in.size()-1;
    int sum = 0;
    while(start <= end){
        sum = in[start] + in[end];
        if(sum == target){
            return 1;
        }
        if(sum > target){
            end--;
        }
        if(sum < target){
            start++;
        }
    }
    return 0;
}
int main()
{
    Node *root = NULL;
    takeInput(root);
    levelOrderTraversal(root);
    cout<<endl;
    int target;
    cout<<"Enter target: "<<endl;
    cin>>target;
    cout<<"Target? "<<twoSumInBST(root, target)<<endl;
    return 0;
}