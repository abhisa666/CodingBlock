#include<iostream>
using namespace std;

template<typename T>
class node
{
    public:
    T data;
    node<T> *next;

    node(T x)
    {
        data=x;
        next=NULL;
    }
};

template<typename T>
class linklist
{
    public:
    node<T> *head;
    node<T> *tail;

    linklist()
    {
        head=NULL;
        tail=NULL;
    }
// Insert at front
    void insert_at_front(T x)
    {
        if(head==NULL)
        {
            head=new node<T>(x);
            tail=head;
        }
        else
        {
            node<T>* temp = new node<T>(x);
            temp->next = head;
            head = temp;
        }
        
    }
// Calculate the length
    int length()
    {
        int count=0;

        node<T> *temp=head;
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
        node<T> *temp = head;
        while(temp!=NULL)
        {
            cout<<temp->data<<" --> ";
            temp = temp->next;
        }
    }

// Insert at the end
    void insert_at_end(T x)
    {
        if(head==NULL)
        {
            head=new node<T>(x);
            tail = head;
        }
        else
        {
            node<T> *temp=new node<T>(x);
            tail->next=temp;
            tail=temp;

        }
        
    }

    // Delete from front
    void delete_at_front()
    {
        if(head==NULL)
        {
            return;
        }
        else
        {
            node<T> *temp=head;
            head=head->next;
            delete temp;
        }
        
    }   

};    
