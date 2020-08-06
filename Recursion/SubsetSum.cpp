#include<iostream>
#include<vector>
using namespace std;

void subSum(int *a,int n,vector<int> v,int sum)
{
	if(sum==0)
	{
		for(auto x:v)
			cout<<x<<" ";

		cout<<endl;
		return;
	}

	if(n==0)
		return;

	//1.do no include lst element
	subSum(arr,n-1,v,sum);
	//2.include last element
	v.push_back(arr[n-1]);
	subSum(arr,n-1,v,sum-arr[n-1]);
}

int main()
{
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	int k;
	cin>>k;

	vector<int> v;

	subSum(arr,n,v,k);




	return 0;
}