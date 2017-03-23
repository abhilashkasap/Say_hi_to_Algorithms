#include<stdio.h> //arrange array elements
int checkprime(int n)
{
	int flag;
	flag=1;int i;
	for(i=2;i<n;i++)
	if(n%i==0)
	{
		flag=0;
		break;
	}
	if(n==0)
	flag=0;
	
	return flag;
}
int main()
{
	
	int a[]={45,23,1,0,56,2,11,9,76,10};
	int prime[10];int odd[10]; int rest[10];
	int i;int primec;int oddc;int restc; restc=0,primec=0,oddc=0;
	for(i=0;i<10;i++)
	{
		
		if(checkprime(a[i]))
		{
		
		prime[primec++]=a[i];
	
	}
		else
		if(a[i]%2!=0)
		{
		
		odd[oddc++]=a[i];
	
	}
		else
		rest[restc++]=a[i];
	}
	
	for(i=0;i<primec;i++)
	printf("\n %d",prime[i]);
	
	for(i=0;i<oddc;i++)
	printf("\n %d",odd[i]);
	for(i=0;i<restc;i++)
	printf("\n %d",rest[i]);
	
	return 0;
}

