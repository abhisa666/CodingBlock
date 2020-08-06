#include<iostream>
#include "ll.h"
#include<list> //ll

using namespace std;

class mystack
{
    public:

    linklist l;

    void push(int x)
    {   
        l.insert_at_front(x);  
    }

    void pop()
    {
        l.delete_at_front();
    }

    int size()
    {
        int s = l.length();
        return s;
    }

    bool empty()
    {
        return size()==0;
        
        
    }

    int top()
    {
        if(size()!=0)
        {
            int t =  l.head->data;
            return t;
        }
        else
        {
            return -1;
        }
        
        
    }




};

int main()
{  
    mystack s;

    s.push(1);
    s.push(2);
    s.push(8);
    s.push(4);

    s.pop();
    s.pop();

    // for(int i=0;i<4;i++)
    // {
    //     s.push(i);
    // }

    // while(!s.empty())
    // {
    //     cout<<s.top();
    //     s.pop();
    // } 

    int t = s.top();

    cout<<s.size()<<endl<<t<<endl<<boolalpha<<s.empty();

    return 0;
}