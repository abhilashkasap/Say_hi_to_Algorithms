#include<iostream>
using namespace std;
#define V 5
#define INFI 9999
void floyds(int adj[][V])
{
	
	int dist[V][V];
	for(int i=0;i<V;i++)
	 {
	 	for(int j=0;j<V;j++)
	 	{
	 		
	 		if(adj[i][j]==0)
	 		dist[i][j]=INFI;
	 		else
	 		dist[i][j]=adj[i][j];
		 }
	 }
	 
	 for(int k=0;k<V;k++)
	 {
	 	
	 	for(int i=0;i<V;i++)
	 	{
	 		
	 		for(int j=0;j<V;j++)
	 		{
	 			
	 			if(dist[i][j]>(dist[i][k]+dist[k][j]))
	 			dist[i][j]=dist[i][k]+dist[k][j];
			 }
		 }
	 }
	 
	 for(int i=0;i<V;i++)
	 {
	 	for(int j=0;j<V;j++)
	 	{
	 		
	 		cout<<dist[i][j]<<"  ";
		 }
		 cout<<endl;
	 }
	 
}
int main()
{
	
	int a[V][V]={{0,0,1,0,1},
                    {0,0,1,1,1},
                    {1,1,0,0,1},
                    {0,1,0,0,1},
                    {1,1,1,1,0}};
                    
    floyds(a);
    return 0;

}
