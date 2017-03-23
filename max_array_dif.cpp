#include<iostream> //max array difference
using namespace std;
int main()
{
	
	int a[10]={45,34,10,5,-2,56,2,1,677,20};
	int b[10]={10,20,35,47,89,57,100,906,1,0};
	int max=a[0];
	int min=b[0];
	int i=0;
	for(i=0;i<10;i++)
	if(max<a[i])
	max=a[i];
	for(i=0;i<10;i++)
	if(min>b[i])
	min=b[i];
	cout<<" Maximum dif (A-B)= "<<max-min;
}
