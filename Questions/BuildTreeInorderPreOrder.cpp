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

int findElem(int in[], int start, int end, int key){
    for (int i = start; i <= end; i++)
    {
        if(in[i] == key){
            return i;
        }
    }
    return -1;
}

Node* solve(int in[], int pre[], int &index, int inOrderStart, int inOrderEnd, int n){
    if(index>= n || inOrderStart > inOrderEnd){
        return NULL;
    }
    int rootElem = pre[index++];
    Node* root = new Node(rootElem);
    int pos = findElem(in, inOrderStart, inOrderEnd, rootElem);

    root->left = solve(in, pre, index, inOrderStart, pos-1, n);
    root->right = solve(in, pre, index, pos+1, inOrderEnd, n);
    return root;
}

Node* buildTree(int in[], int pre[], int n){
    int preOrderInd = 0;
    Node* ans = solve(in, pre, preOrderInd, 0, n-1, n);
    return ans;
}