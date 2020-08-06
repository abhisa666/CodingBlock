//subsequence of a string

#include<iostream>
using namespace std;

void subs(char *a,int i,char *output,int j)
{
	// base case
	if(a[i]=='\0')
	{
		output[j]='\0';
		cout<<output<<endl;
		return;
	}
	

	output[j]=a[i]; 	// ek baar insertion
	subs(a,i+1,output,j+1);  
	subs(a,i+1,output,j);
		
	
	
}

int main()
{
	char a[]="abc";
	char output[100];
	
	subs(a,0,output,0);
	
	return 0;
}
