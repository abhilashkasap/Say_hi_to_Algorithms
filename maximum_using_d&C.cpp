#include<iostream> //maximum using d and c
#include<cstdlib>

using namespace std;
static int comp;
int max(int a[],int l,int r)
{
	
	if(l>=r)
	return a[l];
	else
	{
		int mid=(l+r)/2;
		int lm= max(a,l,mid);
		int rm= max(a,mid+1,r);
		
		
		if(lm>=rm)
		{
		comp++;
		
		return lm;
	}
		else
		{
		comp++;
		
		return rm;
	}
	}
}
int main()
{
	
	int a[10];
	for(int i=0;i<10;i++)
	a[i]=rand()%9567;
	
for(int  i=0;i<10;i++)
	cout<<a[i]<<endl;
		
	cout<<"\n Maximum element = "<<max(a,0,9)<<endl;
	cout<<" No of comp = "<<comp;
	
	return 0;
}
