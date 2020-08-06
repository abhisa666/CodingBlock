// Permutaion of a string
#include<iostream>
using namespace std;

void permutation(char *s,int i, int j)
{   

    // base case
    if(s[i]=='\0')
    {
    	cout<<s<<endl;
    	return;
	}
	
	for(j=i;s[j]!='\0';j++)
	{
		swap(s[i],s[j]);
		permutation(s,i+1,j+1);
		swap(s[i],s[j]); // back tracking
	}
}

int main()
{
	char s[]="abc";
	
	permutation(s,0,0);
	
	return 0;
}
