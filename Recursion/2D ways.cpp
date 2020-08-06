// 2D matrix no of ways 

#include<iostream>
using namespace std;

int ways(int n,int m)
{
	//base case
	if(n==1&&m==1)
	{
		return 1;
	}
	
	if(n<1 || m<1)
	{
		return 0;
	}
	
	int ans = ways(n,m-1) + ways(n-1,m); 
	
	return ans;
	

}



int main()
{
	
	
	int n;int m;
	cin>>n>>m;
	
	int ans = ways(n,m);
	cout<<ans;
	
	return 0;
}
