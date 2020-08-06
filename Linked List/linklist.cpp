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

// Insert in between
    void insert_in_between(int x,int pos)
    {
        if(pos==0)
        {
            insert_at_front(x);
        }
        
        else if(pos>=length())
        {
            insert_at_end(x);
        }
        else
        {
            node *move=head;
            int moveno=1;
            while(moveno<pos-1)
            {
                move=move->next;
                moveno++;
            }

            node *temp=new node(x);
            temp->next=move->next;
            move->next=temp;

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
            node *temp=head;
            head=head->next;
            delete temp;
        }
        
    }   
// Delete from end

    void delete_at_end()
    {
        if(head==NULL)
        {
            return;
        }
        else
        {
            node *temp = head;
            while(temp->next!=tail)
            {
                temp=temp->next;    
            }

            delete tail;
            temp->next=NULL;
            tail=temp;

        }
        

    }

// Delete in between

    void delete_in_between(int pos)
    {
        if(pos==0)
        {
            delete_at_front();
        }
        else if(pos>length())
        {
            delete_at_end();
        }
        else
        {
            node *temp;
            int moveno=1;
            temp=head;
            while(moveno<pos-1)
            {
                moveno++;
                temp=temp->next;
            }
            node* deltemp = temp->next;
            temp->next=deltemp->next;
            delete deltemp;
        }
        
    } 


    // Find element by recursion
    bool findhelper(node *h,int x)
    {
        
        if(h==NULL)
        {
            return false;
        }
        else if(h->data==x)
        {
            return true;
        }
        else
        {
            return findhelper(h->next,x);
        }


    } 

    bool findelement(int x)
    {
        return findhelper(head,x);
    } 

    // find mid point - data
    int midelement()
    {
        if(!head)
        return -1;

        node *temp1=head;
        node *temp2=head;

        while(temp2 && temp2->next)
        {
            temp2=temp2->next->next;
            temp1=temp1->next;
        }

        return temp1->data;
    }



};

// merge link lists
node* mergeLL(node* a,node* b)
{
    if(a==NULL)
    return b;
    if(b==NULL)
    return a;

    node* c;

    if(a->data<b->data)
    {
        c=a;
        c->next = mergeLL(a->next,b);
    }
    else
    {
        c=b;
        c->next = mergeLL(a,b->next);
    }

    return c;
    
}

node* midelement(node* head)
    {
        if(!head)
        return NULL;

        node *temp1=head;
        node *temp2=head;

        while(temp2 && temp2->next)
        {
            temp2=temp2->next->next;
            temp1=temp1->next;
        }

        return temp1;
    }

//merge sort
node* mergesort(node* head)
{
    //base case
    if(head==NULL || head->next==NULL)
    {
        return head;
    }

    node* mid = midelement(head);
    node* a=head;
    node* b=mid->next;
    mid->next=NULL;
    a=mergesort(a);
    b=mergesort(b);
    node* newhead= mergeLL(a,b);
    return newhead;


}




int main()
{
    linklist l1;

    // for(int i=1;i<=10;i++)
    // {
    //     l.insert_at_front(i);
    // }

    // for(int i=1;i<=10;i++)
    // {
    //     l.insert_at_end(i);
    // }

    // l.insert_in_between(100,3);

    // int len = l.length();
    // cout<<len<<endl;
    
    // l.delete_at_front();
    // l.delete_at_end();
    // l.delete_in_between(4);

    // l.print();
    // cout<<endl;

    //cout<<l.findelement(5);

    l1.insert_at_end(7);
    l1.insert_at_end(6);
    l1.insert_at_end(5);
    l1.insert_at_end(4);
    l1.insert_at_end(3);
    l1.insert_at_end(2);
    l1.insert_at_end(1);

    // l2.insert_at_end(2);
    // l2.insert_at_end(4);
    // l2.insert_at_end(6);

    // int mid = l.midelement();
    // cout<<mid<<endl;

    //l1.head= mergeLL(l1.head,l2.head);
    l1.head = mergesort(l1.head);

    l1.print();
    
    
    return 0;
}