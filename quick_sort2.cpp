#include<iostream>  //randomized quick_sort
#include<cstdlib>
using namespace std;
void array_swap(int a[],int index1,int index2)
{
	
	int temp;
	temp= a[index1];
	a[index1]=a[index2];
	a[index2]=temp;
}
void quick_sort(int a[],int l,int r)
{
	
	if(l>=r)
	{
		return ;
	}
	else
	{
		
		int pivot= rand()%(r-l+1)+l;
	
		int temp_ = a[pivot];
		a[pivot]=a[l];
		a[l]=temp_;
		pivot=l;
		int lower= l;
		int higher =l;
		
		for(int i=lower+1;i<=r;i++)
		{
			if(a[i]<=a[pivot])
			{
				array_swap(a,i,lower+1);
				lower+=1;
			}
			
	    }
	array_swap(a,lower,pivot);
	quick_sort(a,l,lower-1);
	
	quick_sort(a,lower+1,r);
   }
}
int main()
{
	
	
		int a[5];
	
	for(int i=0;i<5;i++)
	a[i]=rand()%1000;
	cout<<"\n Displaying unsorted data  :"<<endl;
	for(int i=0;i<5;i++)
	cout<<a[i]<<endl;
	
	quick_sort(a,0,4);
	cout<<"\n Displaying sorted data  :"<<endl;
	for(int i=0;i<5;i++)
	cout<<a[i]<<endl;
	return 0;
}

