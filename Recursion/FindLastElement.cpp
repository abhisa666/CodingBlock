#include<iostream>
using namespace std;

int findlast(int *a,int n,int key)
{
    if(n<0)
    {
        return -1;
    }

    if(a[n-1]==key)
    {
        return n-1;
    }

    findlast(a,n-1,key);
}


int main()
{
    int n;
    cin>>n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    int m;
    cin>>m;

    findlast(arr,n,m);

    
    return 0;
}