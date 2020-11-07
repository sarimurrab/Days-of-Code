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

void print(node *root)
{
    if (root == NULL)
        return;

    print(root->left);
    cout << root->data << " ";
    print(root->right);
}

void bfs(node *root) // Not a New Line
{
    if (root == NULL)
        return;

    queue<node *> q;
    q.push(root);

    while (!q.empty())
    {
        node *save = q.front();
        q.pop();
        cout << save->data << " ";

        if (save->left != NULL)
            q.push(save->left);

        if (save->right != NULL)
            q.push(save->right);
    }
}

void newline_bfs(node *root)
{
    queue<node *> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty())
    {
        if (q.front() == NULL)
        {
            node * save = q.front();
            q.pop();
            if(!q.empty())
            {
                cout<<endl;
                q.push(NULL);

            }

        }
        else
        {
            node *save = q.front();
            cout << save->data << " ";
            q.pop();

            if (save->left != NULL)
                q.push(save->left);

            if (save->right != NULL)
                q.push(save->right);
        }
    }
}

int main()
{
    node *root = build_bt();
    cout << "Inorder Traversal :";
    print(root);
    cout << endl;
    newline_bfs(root);
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

 */
