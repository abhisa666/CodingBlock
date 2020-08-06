// Rat in a maze

#include<iostream>
using namespace std;

bool ratinmaze(char a[][100],int i,int j,int n,int m,int path[][100])
{
	if (i==n-1 && j==m-1)
	{
		path[i][j] = 1;
		for(int i=0;i<n;i++)
    	{
    		for(int j=0;j<m;j++)
    		{
    			cout<<path[i][j]<<" ";
    			
			}
			cout<<endl;
		}
		cout<<endl;
		return false;
		
	}
	
	
	path[i][j]=1;
	//right
	if(a[i][j+1]!='x'&& j+1<m)
	{
		path[i][j+1]=1;
		bool kya_right_se_answer_mila = ratinmaze(a,i,j+1,n,m,path);
		if(kya_right_se_answer_mila)
		{
			return true;
	    }    
	}
	//down
	if(a[i+1][j]!='x'&& i+1<m)
	{
		path[1+1][j]=1;
		bool kya_down_se_answer_mila = ratinmaze(a,i+1,j,n,m,path);
		if(kya_down_se_answer_mila)
		{
			return true;
	    } 
    } 
    path[i][j]=0;
    return false;
}


int main()
{
	char a[100][100]={
	
	   "oooo",
	   "oxox",
	   "xooo",
	   "oxoo"
	
	};
	
	int row = 4;
	int column = 4;
	
	
	int path[100][100]={0};
	
	bool ispathavailable = ratinmaze(a,0,0,row,column,path);
    
   // if(ispathavailable)
   // {
    //	for(int i=0;i<row;i++)
    //	{
    //		for(int j=0;j<column;j++)
    //		{
    //			cout<<a[i][j];
	//		}
	//	}
//	}
	
	return 0;
}
