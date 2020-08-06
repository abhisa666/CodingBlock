// N queens Problem

#include<iostream>
using namespace std;

bool is_valid(int board[][100],int n,int i,int j)
{
	for(int k=0;k<n;k++)
	{
		if(board[i][k] || board[k][j])
		{
			return false;
		}
	}
	
	//diagnal
	int ri=i;
	int rj=j;
	while(ri>=0 && rj>=0)
	{
		if(board[ri][rj]==1)
		{
			return false;
		}
		ri--;
		rj--;
   }
   
   ri=i;
   rj=j;
   
   	while(ri>=0 && rj<=n)
	{
			if(board[ri][rj]==1)
		{
			return false;
		}
		
		ri--;
		rj++;
	}
		
	
	
	return true;
}


bool nqueen(int board[][100],int n,int i)
{
	//base case
	if(i==n)
	{
		//board[i][j] = 1;
		
		for(int i=0;i<n;i++)
    	{
    		for(int j=0;j<n;j++)
    		{
    			cout<<board[i][j]<<" ";
    			
			}
			cout<<endl;
		}
		cout<<endl;
		
		return false;
	}
	
	//recursive case
	
	for(int j=0;j<n;j++)
	{
		if(is_valid(board,n,i,j))
		{
			board[i][j]=1;
			bool kya_aage_se_baat_bani = nqueen(board,n,i+1);
			if(kya_aage_se_baat_bani)
			{
				return true;
			}
			board[i][j]=0;
		}
	}
	
	return false;
	
}

int main()
{
	int n;
	cin>>n;
	
	int board[100][100]={0};
	
	
	nqueen(board,n,0);
	
	
	return 0;
}
