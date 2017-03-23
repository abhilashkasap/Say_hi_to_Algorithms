#include<iostream>
using namespace std;
#define V 5
#define INFI 9999
void bellman_ford(int adj[][V],int s)
{
	int visited[V];
	int dist[V];
	for(int i=0;i<V;i++)
	{
		visited[i]=0;
		dist[i]=INFI;
	}
	dist[s]=0;
	for(int i=0;i<V-1;i++)
	{
		for(int j=0;j<V;j++)
		{
			
			for(int k=0;k<V;k++)
			{
				
				if(adj[j][k]!=0)
				{
					
					if(dist[k]>(adj[j][k]+dist[j]))
					{
						dist[k]=adj[j][k]+dist[j];
					}
				}
			}
		}
		
	}
	
	cout<<"Shortest Distance :-"<<endl;
	for(int i=0;i<V;i++)
	{
		cout<<"i : "<<i<<"  Distance : "<<dist[i]<<endl;
	} 
}
int main()
{
	
	int adj[V][V]={{0,0,1,0,15},
                    {0,0,5,2,5},
                    {1,5,0,0,1},
                    {0,2,0,0,3},
                    {15,5,1,3,0}};
    bellman_ford(adj,0);
    return 0;
}
