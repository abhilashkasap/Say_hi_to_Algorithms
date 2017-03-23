#include<iostream> //n c r calculation - brute force approach
using namespace std;
int ncr( int n,int r)
{
	
	if(r==0||r==n)
	return 1;
	else
	return (ncr(n-1,r)+ncr(n-1,r-1));
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
