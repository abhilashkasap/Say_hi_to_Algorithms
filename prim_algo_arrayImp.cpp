
#include<iostream> //prim's algorithm
using namespace std;
#define V 5
#define INFI 9999
void prims(int adj[][V])
{   static int c;
	int edge[V-1][2]={0};
	int visited[V];
	int nbr[V];
	int dist_v[V];
	for(int i=0;i<V;i++)
	{
		visited[i]= 0;
		nbr[i]=-1;
		dist_v[i]=INFI;
	}
	
	visited[0]=1;
	for(int i=0;i<V;i++)
	{
		if(adj[0][i]!=0)
		dist_v[i]=adj[0][i];
		nbr[i]=0;
		
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
		edge[c][0]=nbr[u];
		edge[c][1]=u;
		c++;
		for(int i=0;i<V;i++)
		{
			
			if(adj[u][i]!=0&&visited[i]==0)
			if(dist_v[i]>adj[u][i])
			  {
			  	dist_v[i]=adj[u][i];
			  	nbr[i]=u;
			  }
		}
	}
	
	cout<<"See added edges :- "<<endl;
	for(int i=0;i<V-1;i++)
	{
		cout<<"s : "<<edge[i][0]<<endl;
		cout<<"d : "<<edge[i][1]<<endl;
	}
}

int main()
{
	
	int adj[V][V]={{0,0,1,0,15},
                    {0,0,5,2,5},
                    {1,5,0,0,1},
                    {0,2,0,0,3},
                    {15,5,1,3,0}};
    prims(adj);
    return 0;
}
