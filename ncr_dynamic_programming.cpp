#include<iostream>
using namespace std;
int ncr(int n,int r)
{
	
	int a[n+1][r+1];
	for(int i=0;i<=n;i++)
	{
		
		for(int j=0;j<=r;j++)
		{
			
			if(j==0||i==j)
			a[i][j]=1;
			
			
		}
	}
	
	for(int i=2;i<=n;i++)
	{
		for(int j=1;j<i&&j<=r;j++)
		{
			
			a[i][j]=a[i-1][j]+a[i-1][j-1];
		}
	}
	
	
	

	return a[n][r];
}

int main()
{
	
	int n,r;
	cout<<"Enter Value of n =";
	cin>>n;
	cout<<"Enter Value of r=";
	cin>>r;
	cout<<"\n Answer ="<<ncr(n,r);
	return 0;
}


