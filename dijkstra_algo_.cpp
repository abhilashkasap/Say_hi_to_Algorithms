
#include<iostream> //dijkstra's algorithm
using namespace std;
#define V 5
#define INFI 9999
void dijkstra(int adj[][V],int s)
{   
	
	int visited[V];
	
	int dist_v[V];
	for(int i=0;i<V;i++)
	{
		visited[i]= 0;
		
		dist_v[i]=INFI;
	}
	
	visited[s]=1;
	dist_v[s]=0; //distance of source vertex
	for(int i=0;i<V;i++)
	{
		if(adj[s][i]!=0)
		dist_v[i]=adj[s][i];
		
		
	}
	for(int i=1;i<V;i++)
	{
		
		int u=-1;
		int dist=INFI;
		for(int i=0;i<V;i++)
		{
			if(dist_v[i]<dist&&visited[i]==0)
			{
			dist=dist_v[i];
			u=i;
		    }
		}
		visited[u]=1;
		
		for(int i=0;i<V;i++)
		{
			
			if(adj[u][i]!=0&&visited[i]==0)
			if(dist_v[i]>(adj[u][i]+dist_v[u]))
			  {
			  	dist_v[i]=adj[u][i]+dist_v[u];
			  	
			  }
		}
	}
	
	cout<<"See shortest path  :- "<<endl;
	for(int i=0;i<V;i++)
	{
		cout<<" i = "<<i<<"  Distance : "<<dist_v[i]<<endl;
	}
}

int main()
{
	
	int adj[V][V]={{0,0,1,0,15},
                    {0,0,5,2,5},
                    {1,5,0,0,1},
                    {0,2,0,0,3},
                    {15,5,1,3,0}};
    dijkstra(adj,0);
    return 0;
}
