#include<iostream> //sorting file
#include<cstdlib>
#include<fstream>
#define INFI 99999
using namespace std;

void merge(int a[],int l,int m,int r)
{   
    int i;
	int n1= m-l+1;
	int n2=r-m;
	int *left_temp = new int[n1+1];
	int *right_temp= new int[n2+1];
	for(i=0;i<n1;i++)
	{
		left_temp[i]= a[l+i];
	}
	left_temp[i]=INFI;
	
	for(i=0;i<n2;i++)
	{
		right_temp[i]=a[m+1+i];
	}
	
	right_temp[i]=INFI;	
	int j,k;
	j=0;k=0;
	for(i=l;i<=r;i++)
	{
		if(left_temp[j]<=right_temp[k])
		{
			a[i]=left_temp[j];
			j++;
		}
		else
		{
			a[i]=right_temp[k];
			k++;
		}
	}
}
	
	

	
	

void merge_sort(int a[],int l,int r)
{
	if(l==r)
	{  
	   return;
	}
	else
	{
		int mid= (l+r)/2;
		merge_sort(a,l,mid);
		merge_sort(a,mid+1,r);
		merge(a,l,mid,r);
		
	}
	
}


int main()
{
	ofstream ofs("myfile.txt");
	for(int i=0;i<100;i++)
	ofs<<rand()%100<<endl;
	int i=0;
	ofs.close();
	int a[100];
	ifstream ifs("myfile.txt");
	
	while(!ifs.eof())
    {
    	
    	char ch[20];
    	ifs>>ch;
    	cout<<ch<<endl;
    	int temp;
    	temp=atoi(ch);
    	a[i]=temp;
    	i++;
		}
		
		ifs.close();
		merge_sort(a,0,99);
		cout<<"\n Sorted Data :";
		for(i=0;i<100;i++)
		{cout<<a[i]<<endl;
			}
			
		ofstream of("myfile.txt",ios::out);
		for(i=0;i<100;i++)
		of<<a[i]<<endl;
		of.close();
		return 0;		
}
