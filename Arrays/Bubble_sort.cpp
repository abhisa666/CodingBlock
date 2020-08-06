#include<iostream>
using namespace std;
 
// a comparetor funtion
bool compare(int a,int b)
{
    return  a>b;
}

// It has pairwise swaping
void bubble_sort(int arr[],int n, bool (&comp)(int a,int b) ) // pass a function as a parameter to another function
{
    for(int i=1;i<=n-1;i++) // here i denotes iterations...-> here 1 itr is used to move a big element to the last
    {   //biggest element moves to the right
        for(int j=0;j<=n-i-1;j++)    // j < n-i-1
        {
            // pairwise swaping in unsorted array

            if( comp(arr[j],arr[j+1]) ) 
                swap(arr[j],arr[j+1]);
        }
    }


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

    bubble_sort(arr,n,compare);

    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}