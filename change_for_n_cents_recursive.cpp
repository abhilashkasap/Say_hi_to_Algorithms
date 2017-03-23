#include<iostream> // change for n-cents recursive
using namespace std;
int change(int n)
{
	if(n==0)
	return 0;
	else
	if(n<0)
	return 99999;
	else
	{
		
		int p=change(n-1);
		int q=change(n-25);
		int d=change(n-10);
		int ni=change(n-5);
		int min=p;
		if(min>q)
		min=q;
		if(min>d)
		min=d;
		if(min>ni)
		min=ni;
		return (1+min);
		
	}
}

int main()
{
	
	cout<<change(37);
	return 0;
}
