#include<iostream>
#include<cstring>

using namespace std;

int stoi(char *a,int n)
{
   if(n==-1)
   return 0;
   
   int last= a[n]-'0';
   int ans = stoi(a,n-1) *10 + last;
   
   return ans;
}

int main()
{
	char a[10];
	cin>>a;
	
	int ans = stoi(a,strlen(a)-1);
	
	cout<<ans;
	cout<<ans/10;
}
