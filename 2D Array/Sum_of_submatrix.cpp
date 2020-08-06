#include<iostream>
using namespace std;

int sumofsubMatrix1(int arr[][100],int n,int m)  //brute force 
{
    int sum=0;

    for(int li=0 ; li < n ;li++)
    {
        for(int lj=0 ; lj<m ;lj++)
        {
            for(int bi=li ;bi<n;bi++)
            {
                for(int bj=lj ; bj<m;bj++)
                {
                    for(int i=li;i<=bi;i++)
                    {
                        for(int j=lj;j<=bj;j++)
                        {
                            sum+=arr[i][j];
                        }
                    }
                }
            }
        }
    }


    return sum;
}


int sumofsubMatrix2(int arr[][100],int pre[][100],int n,int m)  //with use of prefix array
{
    int sum=0;

    for(int li=0 ; li < n ;li++)
    {
        for(int lj=0 ; lj<m ;lj++)
        {
            for(int bi=li ;bi<n;bi++)
            {
                for(int bj=lj ; bj<m;bj++)
                {
                    if(li==0 && lj==0)
                    {
                       //sum += ( pre[bi][bj] - pre[li][bj] - pre[bi][lj+1] + pre[li][lj] );
                    }
                    else
                    {
                        sum += ( pre[bi][bj] - pre[li-1][bj] - pre[bi][lj+1] + pre[li-1][lj-1] );
                    }
                    
                    cout<<sum<<"   ";
                }
            }
        }
    }
    cout<<endl;

    return sum;
}

int sumofsubMatrix3(int arr[][100],int n,int m)  //best
 {
    int sum=0;

    for(int i=0 ; i < n ; i++)
    {
        for(int j=0 ; j<m ; j++)
        {
            sum += arr[i][j] * ( (i+1)*(j+1) * (n-i)*(m-j) );
        }
    }

    return sum;
}

int main()
{
    int n,m;
    cin>>n>>m;

    int arr[100][100];
    int k=1;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            arr[i][j] =k++;
        }
    }

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }

    int prefix[100][100];

    
    //col wise addition
    for(int i=0;i<n;i++)
    {
        for(int j=1;j<m;j++)
        {
            prefix[i][j]+=arr[i][j-1];
        }
    }

    //row wise addition secondly
    for(int i=0;i<m;i++)
    {
        for(int j=1;j<n;j++)
        {
            prefix[j][i]+=arr[j-1][i];
        }
    }
    
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<prefix[i][j]<<" ";
        }
        cout<<endl;
    }

   cout<<sumofsubMatrix1(arr,n,m)<<endl; //brute force solution  n^6
   cout<<sumofsubMatrix2(arr,prefix,n,m)<<endl; //using prefix array  n^4
   cout<<sumofsubMatrix3(arr,n,m)<<endl; //best n^2

    return 0;
}