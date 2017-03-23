#include<iostream>
#include<cstdlib>
using namespace std;
int main()
{
	
	int a[10];
	for(int i=0;i<10;i++)
	a[i]=rand()%287;
	for(int i=0;i<10;i++)
	cout<<"\n"<<a[i];
	int max=a[0];
	static int comp;
	for(int i=0;i<10;i++)
{    comp++;
		if(max<a[i])
	{
	
	max=a[i];
	
}
}
	cout<<"\n Maximum value :"<<max;
	cout<<endl<<" Comp made ="<<comp;
	return 0;
}
