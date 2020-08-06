#include<iostream>
#include<set>
#include<cstring>
using namespace std;

set<string> print;

void order(string str,int i)
{
	if(i==str.length())
	{	
		print.insert(str);
		return;
	}

	for(int j=i;j<str.size();j++)
	{
        swap(str[i],str[j]);
        order(str,i+1);
        swap(str[i],str[j]);
	}
}

int main() {
	string str;
	cin>>str;

	order(str,0);

	for(auto x:print)
	{
		if(x>str)
		{
			cout<<x<<endl;
		}
	}

	return 0;
}