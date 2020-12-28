#include "bits/stdc++.h"
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

node *build_BT()
{
    int d;
    cin >> d;

    if (d == -1)
        return NULL;
    node *root = new node(d);
    root->left = build_BT();
    root->right = build_BT();

    return root;
}

class HBpair
{
    public:
    int height;
    bool isbalance;
};

HBpair is_balanced_tree(node * root)
{
    HBpair p;

    if(root == NULL)
    {
        p.isbalance = true;
        p.height = 0;
        return p;
    }

    HBpair left = is_balanced_tree(root->left);
    HBpair right = is_balanced_tree(root->right);

    if(abs(left.height-right.height)<=1 && left.isbalance and right.isbalance)
    {
        p.isbalance = true;
        p.height = max(left.height, right.height)+1;
    }
    else
    {
        
        p.isbalance = false;
        p.height = max(left.height, right.height)+1;
    
    }

    return p;

    

}


void print(node *root)
{
    if (root == NULL)
        return;

    print(root->left);
    cout << root->data << " ";
    print(root->right);
}

int main()
{

    node *root = build_BT();
    HBpair p = is_balanced_tree(root);
    cout<<p.isbalance;
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
