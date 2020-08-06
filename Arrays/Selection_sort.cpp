#include<iostream>
#include<climits>
using namespace std;

void selection_sort(int arr[],int n)
{
    for(int i=0;i<n-1;i++)
    {
        // find the smallest element index from the un-sorted array
        int min_index = i;
        for(int j=i;j<=n-1;j++)
        {
            if(arr[j]<arr[min_index])
                min_index = j;
        }
        // now we have the min index and we can swap it
        swap(arr[i],arr[min_index]);
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

    selection_sort(arr,n);

    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }

    
    return 0;
}