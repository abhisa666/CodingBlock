#include<iostream>
#include "ll.h"
using namespace std;

node* lastposele(node* head,int pos)
{
    node* temp=head;
    int count=0;
    while(count<pos)
    {
        temp=temp->next;
        count++;
    }
    while(temp!=NULL)
    {
        temp=temp->next;
        head=head->next;
    }

    return head;
}

int main()
{
    linklist l;
    for(int i=1;i<=10;i++)
    {
        l.insert_at_end(i);
    }
    int pos;
    cin>>pos;

    node* ans=lastposele(l.head,pos);
    cout<<ans->data;
    

    return 0;
}