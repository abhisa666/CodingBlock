#include<iostream>
using namespace std;
int main() {
	int n;
	cin>>n;
	int no;
	int digit;
	while(n>0)
	{	cin>>no;
		int ans=0;
		int p=1;
		
		while(no>0)
		{
			digit = no%10;
			ans = ans + (digit*p);
			p=p*2;
			no=no/2;
		}
		cout<<ans<<endl;
		n--;

	}
	return 0;
}