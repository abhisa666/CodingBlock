#include<iostream>
using namespace std;

void insertion_sort(int arr[],int n)
{
    for(int i=1;i<=n-1;i++)
    {
        int e = arr[i]; // we got the element
        int j =i-1;

        // now we find the right place for this element to place

        while (j>=0 && arr[j]>e)
        {
            arr[j+1] = arr[j];
            j--;
        }

        arr[j+1] = e;
        
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


    insertion_sort(arr,n);

    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}