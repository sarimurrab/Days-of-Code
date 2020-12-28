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


node * build_tree()
{
    int d;
    cin>>d;
    if(d==-1)
    return NULL;

    node * root = new node(d);
    root->left = build_tree();
    root->right = build_tree();

    return root;
}

void print(node * root)
{
    if(root ==NULL)
    return;

    print(root->left);
    cout<<root->data<<" ";
    print(root->right);
}


bool print_all_ancestor(node * root, int target)
{
    
    if(root==nullptr)
    return false;

    if(root->data == target)
    {
        //cout<<target<<" "; If the target is ancestor of itself
        return true;
    }


    if(print_all_ancestor(root->left,target) || print_all_ancestor(root->right,target))
    {
        
        cout<<root->data<<" ";
        return true;
    }
    return false;

}

int print_at_zero_level(node * root, int k)
{
    if(root==NULL)
    return 0;
    if(k==0)
    cout<<root->data<<" ";

    
    print_at_zero_level(root->left,k-1);
    print_at_zero_level(root->right,k-1);
    return 0;
}


int print_at_distance(node * root, node * target, int k)
{
    if(root==NULL)
    return -1;
    if(root==target)
    {
        print_at_zero_level(target,k);
        return 0;
    }

    int dl = print_at_distance(root->left,target,k);
    if(dl!=-1)
    {
        if(dl+1==k)
        cout<<root->data<<" ";
        else
        {
            print_at_zero_level(root->right, k-2-dl);
        }
        return dl+1;
        
    }
    int dr = print_at_distance(root->right,target,k);
    if(dl!=-1)
    {
        if(dr+1==k)
        cout<<root->data<<" ";
        else
        {
            print_at_zero_level(root->left, k-2-dr);
        }
        return dr+1;
        
    }

    return -1;
}


node * lca(node * root, int a, int b)
{
    if(root==NULL)
    return NULL;

    if(root->data==a || root->data ==b)
    return root;

    node * left = lca(root->left, a,b);
    node * right = lca(root->left, a,b);
    if(left!=NULL and right!=NULL)
    return root;

    if(left!=NULL)
    return left;

    return right;

}




int main()
{
    node * root = build_tree();
    
    node * lcs = lca(root,10,3);
    cout<<lcs->data;
    
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