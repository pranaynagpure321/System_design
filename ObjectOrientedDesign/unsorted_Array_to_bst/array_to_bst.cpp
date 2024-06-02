
#include<iostream>
#include<vector>

using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;

    Node(int val) : data(val), left(NULL) , right(NULL) {}

};

Node * insert(Node *node, int value)
{
    if(node == NULL) return new Node(value);

    if(node->data > value) node->left = insert(node->left, value);

    else if(node->data < value) node->right = insert(node->right, value);

    return node;
}


Node * array_to_bst(vector<int> &arr)
{
    Node *root = NULL;
    for(int i : arr)
    {
        root = insert(root,i);
    }
    return root;
}


void inorder(Node *root)
{
    if(!root) return ;

    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

int main()
{
    vector<int> arr ={8,7,1,2,12,5};
    cout<<"Pranay here"<<endl;
    Node *root = array_to_bst(arr);
    inorder(root);
    cout<<"Pranay after here"<<endl;
}
