#include<iostream> //finding kth smallest using quick sort approach
#include<cstdlib>
using namespace std;
void quickgetk(int a[],int l,int r,int k)
{
	
	if(l>=r)
	return ;
	else
	{
		
		
		int pivot=l;
		int lp,rp;
		lp=l;
		rp=l+1;
		for( ; rp<=r;rp++)
		{
			if(a[rp]<=a[pivot])
			{
				int temp=a[lp+1];
				a[lp+1]=a[rp];
				a[rp]=temp;
				lp++;
			}
			
		}
		
		int temp=a[pivot];
		a[pivot]=a[lp];
		a[lp]=a[pivot];
		if(k==lp)
		{
		cout<<" kth smallest element :"<<a[lp];
		return;
	}
		else
		{
			if(k>lp)
			quickgetk(a,lp+1,r,k);
			else
			quickgetk(a,l,lp-1,k);
		}
	}
}
int main()
{
	
	int a[20];
	for(int i=0;i<20;i++)
	a[i]=rand()%10;
	
	
	for(int i=0;i<20;i++)
	cout<<"\n"<<a[i];
	cout<<"Enter value of k";
	int k;
	cin>>k;
	
	quickgetk(a,0,19,k);
	return 0;
	
}
