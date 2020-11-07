#include "iostream"
#include "queue"
using namespace std;

class node
{
public:
    int data;
    node *left;
    node *right;
    node(int d)
    {
        data = d;
        left = NULL;
        right = NULL;
    }
};

node *build_bt()
{
    int d;
    cin >> d;
    if (d == -1)
        return NULL;

    node *root = new node(d);
    root->left = build_bt();
    root->right = build_bt();

    return root;
}


int height(node * root)
{
    if(root==NULL)
    return 0;

    return max(height(root->left),height(root->right))+1;
}

int diameter(node * root)
{
    if(root == NULL)
    return 0;

    return height(root->left)+height(root->right);
}

int main()
{
    node *root = build_bt();
    cout << diameter(root);
    
}

/*
INPUT:


1 2 4 -1 -1 -1 3 -1 5 -1 -1



        1
    2       3
 4              5






1 2 4 -1 -1 8 -1 -1 3 3 -1 -1 5 -1 -1

         1
    2       3
 4     8  3     5





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
