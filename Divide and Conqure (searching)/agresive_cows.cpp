#include<iostream>
using namespace std;
//place cows in the stalls by maximinzing the min distance between two cows
bool KyaCowRakhPaye(int stalls[],int n,int cow,int min_sep)
{   
    int last_cow = stalls[0];
    int count=1;

    for(int i=1;i<n;i++)
    {
        if( (stalls[i]-last_cow) >= min_sep )
        {
            last_cow = stalls[i];
            count++;
            if(count==cow)
                return true;
        } 
    }

    return false;
}
int main()
{
    int stalls[] = {1,2,6,11,13};
    int n=5;
    int cows = 3;

    //define a monotonic search space for min distance between cows
    // 0 , 1 ,2 ,3 ,4, 5, 6, 7, 8 these are the posible min distance between cows for given stalls
    // now we have to find the maximum ( min distance ) from this search space so that we can place our cows

    int s=0;
    int e=stalls[n-1] - stalls[0];
    int ans=0;

    while(s<=e)
    {
        int mid=(s+e)/2;

        if(KyaCowRakhPaye(stalls,n,cows,mid))
        {
            ans = mid;
            s = mid +1;
        }
        else
        {
            e=mid-1;
        }
        
    }

    cout<<ans;

    return 0;
}