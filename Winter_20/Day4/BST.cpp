#include "iostream"
using namespace std;

class node
{
    public:
    int data;
    node * left;
    node * right;
    node(int d)
    {
        data = d;
        left = NULL;
        right = NULL;
    }
};

node * insert_bst(node * root, int d)
{
    if(root == NULL)
        return new node(d);
    if(d<=root->data)
    {
        root->left = insert_bst(root->left, d);
    }
    else
    {
        root->right = insert_bst(root->right, d);
    }
    return root;
}


void print(node * root)
{
    if(root==NULL)
    return;

    print(root->left);
    cout<<root->data<<" ";
    print(root->right);
}

node * build_BST()
{
    int d;
    cin>>d;
    
    node * root = NULL;
    while(d!=-1)
    {
        root = insert_bst(root,d);
        cin>>d;
    }

    return root;
}





int main()
{
    node * root = build_BST();
    
    print(root);
    
}


/*
1 2 4 -1 -1 8 7 -1 -1 9 10 -1 -1 -1 3 3 -1 -1 5 -1 -1


           1
        /     \
     2          3
   /  \        /   \
 4     8      3     5
      /  \
     7    9
         /
        10

        */