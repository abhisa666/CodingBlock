#include<iostream>
#include<vector>
#include "ll.h"
using namespace std;

template<typename T>

class mystack
{
    public:

    linklist<T> l;

    void push(T x)
    {   
        l.insert_at_front(x);  
    }

    void pop()
    {
        l.delete_at_front();
    }

    int  size()
    {
        int s = l.length();
        return s;
    }

    bool empty()
    {
        return size()==0;
        
        
    }

    T top()
    {
        if(size()!=0)
        {
            return l.head->data;
        }
        else
        {
            return T(0);
        }
        
        
    }




};

int main()
{  
    mystack<char> s;

    s.push('a');
    s.push('A');
    s.push('c');
    s.push('d');

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

