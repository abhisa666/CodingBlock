#include<iostream>
#include<cstring>

using namespace std;

int maxlen(char a[][1000],int n)
{
    int max =0;
    int j;

    for(int i=0;i<n;i++)
    {
        int l = strlen(a[i]);
        if(l>max)
        {
            max = l;
            j = i;
        }
    }

    cout<<a[j]<<" = ";
    return max;

}

int main()
{
    int n;
    cin>>n;
    cin.get();
    char a[n][1000];

    for(int i=0;i<n;i++)
    {
        cin.getline(a[i],1000);
    }

    cout<<maxlen(a,n);

    return 0;
}