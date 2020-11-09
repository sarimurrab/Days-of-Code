#include<bits/stdc++.h>
using namespace std;

class node 
{
    public:
    int data;
    node * next;
    node(int d)
    {
        data = d;
        next = NULL;

    }
};

// insertion at front
void insert_at_front(node * &head, int d)
{
    if(head == NULL)
    {
    head = new node(d);
    return;
    }
    node * temp = new node(d);
    temp->next = head;
    head = temp;
}


// print the linked List
void print(node * head)
{
    if(head == NULL)
    return ;
    while(head!=NULL)
    {
        cout<<head->data<<" ";
        head = head->next;
    }
}


// question - reverse the linked list.
// using recursion

node * reverse_recusrively(node *head)
{
    if(head ==NULL || head ->next ==NULL)
    return head;

    node * small_head = reverse_recusrively(head->next);

    node * temp = head->next;
    temp->next = head;
    head->next = NULL;

    return small_head;

}

// question - reverse the linked list.
// using interative approach.
void reverse_iteratively(node *&head)
{
    node * prev = NULL;
    node * curr = head;
    node * nx;
    while(curr!=NULL)
    {
        nx = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nx;
    }

    head = prev;

}

int main()
{
    node * head = NULL;
    insert_at_front(head,8);
    insert_at_front(head,3);
    insert_at_front(head,11);
    insert_at_front(head,0);
    insert_at_front(head,9);
    insert_at_front(head,1);
    insert_at_front(head,2);

    print(head); cout<<endl;
    head = reverse_recusrively(head);
    print(head); cout<<endl;

    reverse_iteratively(head);
    print(head); cout<<endl;


    return 0;


}