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
	node* head;
	node* tail;

	linklist(){
		head=NULL;
		tail=NULL;
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
	
};

node* appendK(node *head,int k){
    node *oldHead = head;
    node *fast = head;
    node *slow = head;
    for(long i=0;i < k && fast->next!=NULL ;i++){
        fast = fast->next;
    }
    while(fast->next!=NULL && fast!=NULL){
        fast = fast->next;
        slow = slow->next;
    }
    node *newHead = slow->next;
    slow->next = NULL;
    fast->next = oldHead;
    return newHead;
}


int main(){

	linklist l;
	int n;
	cin>>n;
	int x;
	for(int i=0;i<n;i++){
		cin>>x;
		l.insert_at_end(x);
	}

	l.print();


	return 0;
}