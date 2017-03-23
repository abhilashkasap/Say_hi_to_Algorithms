#include<stdio.h> // maximum region
int visited[50][2]={0};
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
static int counter;
int checkvisited(int r,int c)
{
	
	int i;int flag;
	flag=0;
	if(r==-1||c==-1)
	return 0;
	for(i=0;i<counter;i++)
	{
	   if(visited[i][0]==r&&visited[i][1]==c)
	     flag=1;  	
	}
	
	if(flag==1)
	return 0;
	else
	return 1;

}
int max(int a[50][50],int m,int n,int i,int j)
{
	if(i==m||j==n||i==-1||j==-1)
	return 0;
	else
	{
		int r;
		int result;r=0;result=0;
		if(a[i-1][j-1]==1&&checkvisited(i-1,j-1))
		{
			
		visited[counter][0]=i-1;
		visited[counter][1]=j-1;
		counter++;
		r=1+ max(a,m,n,i-1,j-1);
	
		if(result<r)
		result=r;
	    
		}
	     r=0;
	    if(a[i-1][j]==1&&checkvisited(i-1,j))
		{
		visited[counter][0]=i-1;
		visited[counter][1]=j;
		counter++;
		r=1+ max(a,m,n,i-1,j);
		
		if(result<r)
		result=r;
	    
		}	
		r=0;
		if(a[i-1][j+1]==1&&checkvisited(i-1,j+1))
		{
		visited[counter][0]=i-1;
		visited[counter][1]=j+1;
		counter++;
		r=1+ max(a,m,n,i-1,j+1);
		printf("%d\n",r);
		if(result<r)
		result=r;
	    
		}
		r=0;
		if(a[i][j-1]==1&&checkvisited(i,j-1))
		{
		visited[counter][0]=i;
		visited[counter][1]=j-1;
		counter++;
		r=1+ max(a,m,n,i,j-1);
		printf("%d\n",r);
		if(result<r)
		result=r;
	    
		}
		r=0;
		if(a[i][j+1]==1&&checkvisited(i,j+1))
		{
		visited[counter][0]=i;
		visited[counter][1]=j+1;
		counter++;
		r=1+ max(a,m,n,i,j+1);
		printf("%d\n",r);
		if(result<r)
		result=r;
	    
		}
		r=0;
		if(a[i+1][j-1]==1&&checkvisited(i+1,j-1))
		{
		visited[counter][0]=i+1;
		visited[counter][1]=j-1;
		counter++;
		r=1+ max(a,m,n,i+1,j-1);
		printf("%d\n",r);
		if(result<r)
		result=r;
	    
		}
		r=0;
		if(a[i+1][j]==1&&checkvisited(i+1,j))
		{
		visited[counter][0]=i+1;
		visited[counter][1]=j;
		counter++;
		r=1+ max(a,m,n,i+1,j);
		printf("%d\n",r);
		if(result<r)
		result=r;
	    
		}
		r=0;
		if(a[i+1][j+1]==1&&checkvisited(i+1,j+1))
		{
		visited[counter][0]=i+1;
		visited[counter][1]=j+1;
		counter++;
		r=1+ max(a,m,n,i+1,j+1);
		printf("%d\n",r);
		if(result<r)
		result=r;
	    
		}
		return result;
	}
	
}
int main()
{
	visited[counter][0]=0;
	visited[counter][1]=0;
	counter++;
	int a[50][50]={0};
	int m,n;
	int i,j;
	printf("\n Enter Dimension of the matrix :");
	scanf("%d%d",&m,&n);
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		scanf("%d",&a[i][j]);
	}
	
	int result;
	result=0;int temp;temp=0;

for(i=0;i<m;i++)
{
	for(j=0;j<n;j++)
	  {
	  	temp=max(a,m,n,i,j);
	  	if(result<temp)
	  	result=temp;
	  }
}
	

	printf("\n Result= %d ",result);
	

	return 0;
}

