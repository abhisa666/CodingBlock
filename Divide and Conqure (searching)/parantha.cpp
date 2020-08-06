#include<iostream>
using namespace std;

bool kya_p_parathe_ban_jayenge_mid_time_mai(int ranks[],int no_of_cooks,int p,int time)
{
    int count = 0;
    for(int i = 0;i < no_of_cooks; i++){
        //count parathas made by ith cook in mid time
        int t = 0;
        int j = 1;
        while(1)
        {
            t += j*ranks[i];
            j++;
            if(t > time)
                break;
            count++;
        }
    }
    // cout << mid << sp << count << endl;
    return (count >= p);
        
}

int main()
{
    int p;
    cin>>p;

    int no_of_cooks=4;

    int ranks[1000] = {1,2,3,4};

    //search space
    // we need min time so our search space is of time
    // lets say 0 to 100
    int s=0;
    int e=100;
    int ans=0;
    
    while(s<=e)
    {
        int mid=(s+e)/2;

        if(kya_p_parathe_ban_jayenge_mid_time_mai(ranks,no_of_cooks,p,mid))
        {
            cout<<"haan "<<mid<<" min mai "<<p<<" parathe ban jaynege"<<endl;
            ans = mid;
            e=mid-1;
        }
        else
        {
            cout<<"Nahi yaar "<<mid<<" min mai "<<p<<" parathe nahi ban jaynege"<<endl;
            s=mid+1;
        }
        
    }

    cout<<ans<<endl;
   
    return 0;
}