#include<iostream>
using namespace std;
int main() {
	int n;
	cin>>n;
	int car;
	while(n>0)
	{

		cin>>car;
		int sum=0;
		while(car!=0)
		{
			int d=car%10;
			sum =  sum +d;
			car = car/10;
		}
		if(sum%2==0 && sum%4==0)
		{
			cout<<"Yes"<<endl;
		}
		else if(sum%2!=0 && sum%3==0)
		{
			cout<<"Yes"<<endl;
		}
		else
		cout<<"No"<<endl;




		n--;
	}
	return 0;
}