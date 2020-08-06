#include<iostream>
#include<climits>
using namespace std;
int main() {
	int n;
	cin>>n;

	long long int curr;
	long long int p1=1;
	long long int p2=1;

	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=i;j++)
		{
			if(i==1 && j==1)
				cout<<"0";
			else if(i==2 && j==1)
				cout<<"1\t";
            else if(i==2 && j==2)
				{
                    cout<<"1";
                }
            else
			{
				curr = p1 + p2;
				cout<<curr<<"\t";
				p2 = p1;
				p1 = curr;
				
			}
		}
		cout<<endl;
	}


	return 0;
}