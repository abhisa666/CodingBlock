#include<iostream>
using namespace std;
int main() {
	int n;
	cin>>n;

	int a,b;

	if(n%2==0)
	{
		a = ( (n/2)*(n/2) ) - 1;
		b = ( (n/2)*(n/2) ) + 1;
	}
	else
	{	
		a = ( ((n+1)/2)*((n+1)/2) ) - ( ((n-1)/2)*((n-1)/2) );
		b = ( ((n+1)/2)*((n+1)/2) ) + ( ((n-1)/2)*((n-1)/2) );

	}

	cout<<a<<" "<<b;



	return 0;
}