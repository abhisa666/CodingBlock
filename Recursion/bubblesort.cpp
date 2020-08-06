#include<iostream>
using namespace std;

void bubblesort(int *a,int n,int i=0)
{
	if(i==n-1) 
	return;
	
	for(int j =0;j<n-1;j++)
	{
		if(a[j]>a[j+1])
		  swap(a[j],a[j+1]);
	}
	
	bubblesort(a,n,i+1);
	
	
}

int main()
{
	int a[5]={5,4,3,2,1};
	
	int n = sizeof(a)/sizeof(int);
	
	bubblesort(a,n);
	
	for(int i=0;i<n-1;i++)
	{
		cout<<a[i];
	}
	
	return 0;
}
