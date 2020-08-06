#include<iostream>
#include "ll.h"
using namespace std;


// detect cycle
void cycledetection(node* head)
{
    node* s=head;
    node* f=head;

    while(s->data!=f->data)
    {
        f=f->next->next;
        s=s->next;
    }
    s=head;
    while (s->next->data!=f->next->data)  // FYLO   D Cycle detection
    {
       s=s->next;
       f=f->next;
    }

    f->next=NULL;
    
}

node* reverse(node* head)
{
    node* curr = head;
    node* prv = NULL;
    node* next = head;

    while(next!=NULL)
    {
        next = curr->next;
        curr->next = prv;
        prv=curr;
        curr = next;
    }

    return prv;
}

int main()
{
    linklist l;
    for(int i=1;i<=10;i++)
    {
        l.insert_at_end(i);
    }

    l.head = reverse(l.head);

    l.print();
    
    return 0;
}