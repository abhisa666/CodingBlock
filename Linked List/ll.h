#include<iostream>
using namespace std;

class node
{
    public:
    int data;
    node *next;

    node(int x)
    {
        data=x;
        next=NULL;
    }
};

class linklist
{
    public:
    node *head;
    node *tail;

    linklist()
    {
        head=NULL;
        tail=NULL;
    }
// Insert at front
    void insert_at_front(int x)
    {
        if(head==NULL)
        {
            head=new node(x);
            tail=head;
        }
        else
        {
            node* temp = new node(x);
            temp->next = head;
            head = temp;
        }
        
    }
// Calculate the length
    int length()
    {
        int count=0;

        node *temp=head;
        while(temp!=NULL)
        {
            count++;
            temp=temp->next;
        }

        return count;
    }

// Print
    void print()
    {
        node *temp = head;
        while(temp!=NULL)
        {
            cout<<temp->data<<" --> ";
            temp = temp->next;
        }
    }

// Insert at the end
    void insert_at_end(int x)
    {
        if(head==NULL)
        {
            head=new node(x);
            tail = head;
        }
        else
        {
            node *temp=new node(x);
            tail->next=temp;
            tail=temp;

        }
        
    }

};    
