// Tower of Hanoi with Resursion

#include<iostream>
using namespace std;

void toh(int n,char source,char helper, char destination)
{
	
	//base case
	if(n==0)
	return;
	
	//resursive case
	toh(n-1,source,destination,helper);
	cout<<"Moving Disc"<<n<<source<<destination<<endl;
	toh(n-1,helper,source,destination);
}




int main()
{
	int n;
	cin>>n;
	
	toh(n,'A','B','C');
	
	return 0;
}
