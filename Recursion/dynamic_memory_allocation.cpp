#include<iostream>
using namespace std;

int main()
{
    // int *a = new int; // interger
    //  int n;
    //  cin>>n;
    //  int *arr = new int[n]; // array
    
    // delete a; // delete integer
    // delete []a; // array delete

    int r,c;
    cin>>r;
    cin>>c;
    int val=1;

    // 2D array

    int **a = new int* [r];
    for(int i=0;i<r;i++)
    {
        a[i] = new int [c];
    }
    
    ////////////

    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            a[i][j]=val;
            val++;
        }
    }

    for(int i=0;i<r;i++)
    {
        for(int j = 0;j<c;j++)
        {
            cout<<a[i][j]<<" ";
            
        }
        cout<<endl;
    }
    

    //delete 2d array

    // for(int i=0;i<r;i++)
    // {
    //     delete []a[i];
    // }
    // delete []a;


    return 0;


}