#include<iostream>
using namespace std;
int main() {
	
	char ch;
	int a,b;
	

	while(true)
	{
		cin>>ch;

		if(ch=='+')
		{
			cin>>a>>b;
			cout<<a+b<<endl;
		}
		else if(ch=='-')
		{
			cin>>a>>b;
			cout<<a-b<<endl;
		}
		else if(ch=='*')
		{
			cin>>a>>b;
			cout<<a*b<<endl;
		}
		else if(ch=='/')
		{
			cin>>a>>b;
			cout<<a/b<<endl;
		}
		else if(ch=='%')
		{
			cin>>a>>b;
			cout<<a%b<<endl;
		}
		else if (ch=='x'||ch=='X')
		{
			  break;
		}
		else
		{
			cout<<"Invalid operation. Try again."<<endl;
		
		}

		
	}

	return 0;
}