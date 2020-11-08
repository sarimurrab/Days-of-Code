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


int height(node * root)
{
    if(root==NULL)
    return 0;


    return max(height(root->left),height(root->right))+1;
}
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

node * from_in_and_pre(int * in , int * pre, int s, int e)
{
    static int i=0;
    if(s>e)
    return NULL;
    
    // root node -- pre key starting mai hoga
    node * root = new node(pre[i]);

    //Now I will  be looking for for that value in inorder
    int index =-1;
    for(int j=s;j<=e;j++)
    {
        if(in[j]==pre[i])
        {
            index = j;
            break;
        }
    }
    i++;
    // left and right sub tree bnaaye
    root->left = from_in_and_pre(in, pre, s, index-1);
    root->right = from_in_and_pre(in,pre,index+1,e);

    return root;
    
}



void print_at_level(node * root,int k)
{
    if(root==NULL)
    return;

    if(k==1)
    {
    cout<<root->data<<" ";
    return;
    }

    print_at_level(root->left,k-1);
    print_at_level(root->right,k-1);


}



void print_all_levels(node * root)
{
    if(root==NULL)
    return;

    int h = height(root);
    for(int i=0;i<=h;i++)
    {
        print_at_level(root,i);
    }
}

void print(node *root)
{
    if (root == NULL)
        return;

    print(root->left);
    cout << root->data << " ";
    print(root->right);
}


void 

int main()
{

    node *root = build_BT();
    
    int in[] = { 4, 2, 5, 1, 3, 6 }; 
    int pre[] = { 1, 2, 4, 5, 3, 6 };
    // node * root = from_in_and_pre(in,pre,0,5);
    // print(root);

    print_all_levels(root);
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
