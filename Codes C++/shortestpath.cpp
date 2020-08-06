#include <iostream>
using namespace std;
int main() {
    char ch;
    ch = cin.get();
    int x=0;
    int y=0;
    while(ch!='\n')
    {
        if(ch=='N')
        {
            y++;
        }
        else if(ch=='S')
        {
            y--;
        }
        else if(ch=='E')
        {
            x++;
        }
        else
        {
            x--;
        }

        ch = cin.get();
    }

    if(x>0)
    {
        for(int i=1;i<=x;i++)
            cout<<'E';
    }
     if(x<0)
    {
        for(int i=1;i>=x;i--)
            cout<<'W';
    }
    if(y>0)
    {
        for(int i=1;i<=y;i++)
            cout<<'N';
    }
    if(y<0)
    {
        for(int i=1;i>=y;i--)
            cout<<'S';
    }
}
