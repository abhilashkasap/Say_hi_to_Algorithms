#include<iostream>
#include<cstdlib>
using namespace std;
int main()
{
	
	int a[10];
	for(int i=0;i<10;i++)
	{
		a[i]=rand()%10+1;
		
	}
	for(int i=0;i<10;i++)
	{
		cout<<a[i]<<endl;
		
}
}
