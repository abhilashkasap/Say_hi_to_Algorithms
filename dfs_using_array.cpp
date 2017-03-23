#include<iostream>
#include<cstdlib>
using namespace std;
#define SIZE 6
int vertex[SIZE];
int parent[SIZE];
int visited[SIZE];
int adj[SIZE][SIZE];
void dfs(int source)
{
	visited[source]=1;
	cout<<"Visited : "<<source+1<<endl;
	for(int i=0;i<SIZE;i++)
	if(adj[source][i]==1&&visited[i]==0)
	{
	parent[i]=source;
	dfs(i);
    }
	
}

int main()
{
	
	for(int i=0;i<SIZE;i++)
	{
		
		for(int j=0;j<SIZE;j++)
		cin>>adj[i][j];
	}
	
	for(int i=0;i<SIZE;i++)
	{
		
		for(int j=0;j<SIZE;j++)
		cout<<adj[i][j]<<" ";
		cout<<endl;
	}
	
	
	dfs(0); // first as source
}



