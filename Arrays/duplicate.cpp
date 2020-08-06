#include<iostream>
#include<cstring>
using namespace std;

void trim(char a[])
{
    int l = strlen(a);
    if(l==1 || l==0)
        return;

    int prev =0;
    for(int cur=1;cur<l;cur++)
    {
        if(a[cur]!=a[prev])
        {
            prev++;
            a[prev] = a[cur];
        }
    }    
    a[prev+1] = '\0';
}
int main()
{
    char a[100];
    cin>>a;

    trim(a);

    cout<<a;
    
    return 0;
}