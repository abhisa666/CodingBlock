// Sudoku solver

#include<iostream>
#include<cmath>
using namespace std;


bool is_valid(int mat[][9],int i,int j, int num,int n)
{
	for(int k=0;k<n;k++)
	{
		if(mat[i][k] == num || mat[k][j]==num)
		{
			return false;
		}
	}
	
	//box
	
	 n = sqrt(n);
	int si=(i/n)*n;
	int sj=(j/n)*n;
	
	for(int p=si;p<si+n;p++)
	{
		for(int q=sj;q<sj+n;q++)
		{
			if(mat[p][q]==num)
			{
				return false;
			}
		}
	}
	
	return true;
}

bool sudoku(int mat[][9],int i,int j,int n)
{
	//base case
	if(i==n)
	{
		for(int k=0;i<n;i++)
    	{
    		for(int l=0;j<n;j++)
    		{
    			cout<<mat[k][l]<<" ";
    			
			}
			cout<<endl;
		}
		cout<<endl;
		
		return true;
	}
	
		if(j==n)
	{
		return sudoku(mat,i+1,0,n);
	}
	
	
	if(mat[i][j]!=0)
	{
		return sudoku(mat,i,j+1,n);
	}
	

	
	//number filling
	for(int num=1;num<=n;num++)
		{
			if(is_valid(mat,i,j,num,n))
			{
				mat[i][j]=num;
				
				bool kya_baat_bani=sudoku(mat,i,j+1,n);
				
				if(kya_baat_bani)
				{
					return true;
				}
				
				mat[i][j]=0;
			}
		}
		
		//return true;
	

}

int main()
{

	
	int mat[9][9] ={
	{5,3,0,0,7,0,0,0,0},
	{6,0,0,1,9,5,0,0,0},
	{0,9,8,0,0,0,0,6,0},
	{8,0,0,0,6,0,0,0,3},
	{4,0,0,8,0,3,0,0,1},
	{7,0,0,0,2,0,0,0,6},
	{0,6,0,0,0,0,2,8,0},
	{0,0,0,4,1,9,0,0,5},
	{0,0,0,0,8,0,0,7,9}
	};
	
	
	sudoku(mat,0,0,9);
	
	return 0;
}
