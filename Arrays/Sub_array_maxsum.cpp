#include<iostream>
using namespace std;

void sub_array_maxsum(int arr[],int n)
{
    int maxsum = 0;
    int left =-1;
    int right=-1;

    for(int i=0;i<n;i++)
    {
        for(int j=i;j<n;j++)
        {
            //currsum = 0 for every sub array
            int currsum = 0;
            for(int k=i;k<=j;k++)
            {
                currsum+=arr[k];
            }
            // udpate maxsum if currsum > maxsum
            if(currsum>maxsum)
            {
                maxsum = currsum;
                left = i;
                right = j;
            }
                
            
        }
    }

    

    cout<<maxsum<<endl;
    for(int i=left;i<=right;i++)
    {
        cout<<arr[i]<<" , ";
    }
}

void sub_array_maxsum2(int arr[],int n,int cumsum[])
{
    int maxsum = 0;
    
    int left =-1;
    int right=-1;

    for(int i=0;i<n;i++)
    {
        
        for(int j=i;j<n;j++)
        {
            //currsum = 0 for every sub array
            int currsum = 0;
            
            currsum = cumsum[j] - cumsum[i-1];
            // udpate maxsum if currsum > maxsum
            if(currsum>maxsum)
            {
                maxsum = currsum;
                left = i;
                right = j;
            }
                
            
        }
    }

    

    cout<<maxsum<<endl;
    for(int i=left;i<=right;i++)
    {
        cout<<arr[i]<<" , ";
    }
}


int main()
{
    int n;
    cin>>n;
    int arr[n];
    // int cumsum[1000] = {0};

    // cin>>arr[0];
    // cumsum[0] = arr[0];

    for(int i=0;i<n;i++) // i=1 for subarraysum2
    {
        cin>>arr[i];
       // cumsum[i] = cumsum[i-1] + arr[i];
    }

    //sub_array_maxsum(arr,n);
    
    //sub_array_maxsum2(arr,n,cumsum);

    // Kadanes Algorithm for max sum of sub array

    int cs = 0; //current sum
    int ms = 0; //max sum 

    for(int i=0;i<n;i++)
    {
        cs = cs  + arr[i];
        if(cs<0)
            cs=0;

        ms = max(cs,ms);

    }

    cout<<"Maximum sum is "<<ms<<endl;





    return 0;
}