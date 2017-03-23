#include<stdio.h> // trinagle maximum possible perimeter
void sort(int a[],int size)
{
	int i,j;
	for(i=0;i<size;i++)
	{
		for(j=0;j<size-1;j++)
		{
			
			if(a[j]>a[j+1])
			{
				int temp;
				temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
			}
		}
		
	}
}
int maximum(int a,int b,int c)
{
	if(a>=b&&a>=c)
	return a;
	else
	if(b>=a&&b>=c)
	return b;
	else
	return c;
}
int main()
{
	int a[100];
	int n;int flag;flag=0;
	printf(" Enter the value of n =");
	scanf("%d",&n);
	int i;
	
	int maxarray[10]={0};
	int maxper;
	maxper=0;
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
		
	}
	int j,k;
    for(i=0;i<n;i++)
    {
    	for(j=0;j<n;j++)
    	{
    		for(k=0;k<n;k++)
    		{
    			if(a[i]!=a[j]&&a[i]!=a[k]&&a[j]!=a[k])
    			{  
    			  if(a[i]+a[j]>a[k]&&a[j]+a[k]>a[i]&&a[i]+a[k]>a[j])
				  {  flag=1;
				  	if((a[i]+a[j]+a[k])>maxper)
				  	   {
				  	   	maxarray[0]=a[i];
				  	   	maxarray[1]=a[j];
				  	   	maxarray[2]=a[k];
				  	   	maxper=(a[i]+a[j]+a[k]);
						 }
						 else
						 if((a[i]+a[j]+a[k])==maxper)
						 {
						 	if(maximum(a[i],a[j],a[k])>maximum(maxarray[0],maxarray[1],maxarray[2]))
						 {
							 	maxarray[0]=a[i];
				  	   	maxarray[1]=a[j];
				  	   	maxarray[2]=a[k];
				  	   }
				  	
						 	
						 }
					  }	
				}
			}
		}
	}
	if(flag==0)
	printf("\n -1");
	else
	{
		sort(maxarray,3);
		for(i=0;i<3;i++)
		printf("\n %d",maxarray[i]);
		
	}
	return 0;
}

