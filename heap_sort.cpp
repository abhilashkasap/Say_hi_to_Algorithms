#include<iostream>
#include<fstream>
#include<cstdlib>
using namespace std;
 
void heapify(int a[],int n,int i)
{
	
	int root = i;
	int left = 2*i+1;
	int right = 2*i+2;
	 int large=i;
	 if(left<n && a[left]>a[large])
	  large=left;
	  if(right<n && a[right]>a[large])
	  large=right;
	  
	  if(large!=root)
	  {
	  	
	  	int temp=a[large];
	  	a[large]=a[root];
	  	a[root]=temp;
	  	
	  	 heapify(a,n,large);
	  }
	  
	 
	
}

void buildheap(int a[],int n)
{
	
	for(int i=n/2-1;i>=0;i--)
	heapify(a,n,i);
}

void heap_sort(int a[],int n)
{
	
	buildheap(a,n);
	
	for(int i=n-1;i>=0;i--)
	{
		
		int temp=a[i];
		a[i]=a[0];
		a[0]=temp;
		
		heapify(a,i,0);
	}
}

int main()
{
	int arr[1000];
	ofstream ofs("test.txt");
	for(int i=0;i<1000;i++)
	ofs<<rand()%2387<<endl;
	ofs.close();
	
	ifstream ifs("test.txt");int i=0;
	while(!ifs.eof())
	{
		
		char ch[10];
		ifs>>ch;
		int data=atoi(ch);
		arr[i++]=data;
		
	}
	ifs.close();
	heap_sort(arr,1000);
	for(int i=0;i<1000;i++)
	cout<<"\n"<<arr[i];
	
	ofs.open("test.txt");
	for(int i=0;i<1000;i++)
	ofs<<arr[i]<<endl;
	ofs.close();
	return 0;
}

