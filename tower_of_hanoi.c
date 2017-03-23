#include<stdio.h> //toh
void toh(int n,char a,char b,char c)
{
	if(n==1)
	{
		printf(" \nMove peg from %c to %c",a,c);
	}
	else
	{
		toh(n-1,a,c,b);
		printf(" \nMove peg from %c to %c",a,c);
		toh(n-1,b,a,c);
	}
}
int main()
{
	printf("\n Enter Value of n =");
	int n;
	scanf("%d",&n);
    toh(n,'A','B','C');	
	return 0;
}
