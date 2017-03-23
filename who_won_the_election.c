#include<stdio.h> //who won the election
int main()
{
	
	int a[100];int frequency[100]={0};
	int n;
	scanf("%d",&n);
	int i;
	for(i=0;i<n;i++)
	scanf("%d",&a[i]);
	for(i=0;i<n;i++)
	{
		frequency[a[i]]++;
	}
	int max;
	max=frequency[0];
	for(i=0;i<100;i++)
	if(max<frequency[i])
	max=frequency[i];
	for(i=0;i<100;i++)
	if(frequency[i]==max)
	printf("%d",i);
	return 0;
}
