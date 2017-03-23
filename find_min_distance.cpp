#include<iostream>
using namespace std;
#define INFI 99999
int find_min_distance(int v1,int v2,int n)
{
	int a[n][n];
	for(int i=0;i<n;i++)
	{
		
		for(int j=0;j<n;j++)
		{
			
			if(i-j<=2||j-i<=2)
			{
				
				if(i-j>0)
				a[i][j]=i-j;
				else
				a[i][j]=j-i;
			}
			else
			a[i][j]= INFI;
		}
	}

    
 
    
    for (int k = 0; k < n; k++)
    {
       
        for (int i = 0; i < n; i++)
        {
            
            for (int j = 0; j < n; j++)
            {
               
                if (a[i][k] + a[k][j] < a[i][j])
                    a[i][j] = a[i][k] + a[k][j];
            }
        }
    }
 
   return a[v1-1][v2-1]; 
}	
	
	
	
	
int main()
{
	
	int n;
	cout<<"Enter Value of n =";
	cin>>n;
	int v1,v2;
	cout<<"Enter Vertices = ";
	cin>>v1>>v2;
	cout<<"\n Result ="<<find_min_distance(v1,v2,n);
}
