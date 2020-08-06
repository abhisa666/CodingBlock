// N Stair Case

#include<iostream>
using namespace std;

int nstair(int n,int k )
{
	//base case
	if(n==0)
	{
		return 1;
	}
	
	//resursive case
	
	if(n<0)
	{
		return 0;
	}
	
	int ans=0;
	
	for(int i=1;i<=k;i++)
	{
		ans+=nstair(n-i,k);
	}
	
	return ans;
	//int ans = nstair(n-1,k)+nstair(n-2,k)+nstair(n-3,k);
	//return ans;
	
	
	
}



int main()
{  
    int n;
    cin>>n;
    int k;
    cin>>k;
    
    int ans = nstair(n,k);
    cout<<ans;
	
	
	return 0;
}
