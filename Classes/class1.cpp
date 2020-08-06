#include<iostream>
using namespace std;

class myclass{
    public:
    int x;
    int y;

    myclass(int a,int b)
    {
        x=a;
        y=b;
    }

    bool operator>(myclass &B)
    {
        if(y>B.y)
        {
            return true;
        }

    }
    
    void print()
    {
        cout<<x<<endl;
        cout<<y<<endl;
    }

};


int main()
{
    myclass A(2,3);
    myclass B(1,4);
    
    A.print();
    B.print();
    

    if(A>B)
    {
        cout<<"A is greater than B";

    }
    else
    {
        cout<<"anask";
    }
    
    
    return 0;
}