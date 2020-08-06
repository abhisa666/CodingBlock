//Divide and Conqure Technique
// Merge sort with recursion


#include<iostream>

using namespace std;


void merge(int *a,int *x,int *y,int start,int end)
{
	int mid=(start+end)/2;
	int i=start;
	int j=mid+1;
	
	int k=start;
	
	while(i<=mid && j<=end)
	{
		if(x[i]<y[j])
		{
			a[k]=x[i];
			k++;
			i++;
		}
		else
		{
			a[k]=y[j];
			k++;
			j++;
		}
		
	}
	
	
    	if(i<=mid)
		{
			while(i<=mid)
			{
				a[k]=x[i];
				k++;
				i++;
			}
		}
		
		if(j<=end)
		{
			while(j<=end)
			{
				a[k]=y[j];
				k++;
				j++;
			}
		}
}

void mergesort(int *a,int start,int end)
{
	//base case
	if(start>=end)
	return;
	
	//divdie
	int x[100];
	int y[100];
	int mid=(start+end)/2;
	
	for(int i=start;i<=mid;i++)
	{
		x[i]=a[i];
		
	}
	
	for(int j=mid+1;j<=end;j++)
	{
		y[j]=a[j];
		
	}
	
	//left array
	mergesort(x,start,mid);
	//right array
	mergesort(y,mid+1,end);
	
	//merge
	merge(a,x,y,start,end);
	
	
}


int main()
{
	int a[5]={5,2,4,3,1};
	int n=sizeof(a)/sizeof(int);
	
	mergesort(a,0,n-1);
	
	for(int i=0;i<n;i++)
	{
		cout<<a[i];
	}
	
	return 0;
}
