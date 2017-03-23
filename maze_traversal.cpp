#include<iostream>
using namespace std;
#define M 4 //change Maze Size
#define V 16 //a/c to that change V
#define INFI 99999
int adj[V][V]; //adjacency matrix
static int s;
static int dest;
void createadj(int maze[][M])
{
	int c=-1;
	for(int i=0;i<M;i++)
	{
		
		for(int j=0;j<M;j++)
		{
			c++;
			if(maze[i][j]==1)
			{ 
			s=c;
			
		    }
			
			if(maze[i][j]==2)
			dest=c;
			
			
				if(maze[i][j+1]!=0&&j<M)
				 adj[c][c+1]=1;
				if(maze[i][j-1]!=0&&j>=0)
				adj[c][c-1]=1;
				if(maze[i-1][j]!=0&&i>=0)
				adj[c][c-4]=1;
				if(maze[i+1][j]!=0&&i<M)
				adj[c][c+4]=1;
			
			
		}
	}
	adj[1][14]=0;
	cout<<"See Adj :- "<<endl;
	for(int i=0;i<V;i++)
	{
		
		for(int j=0;j<V;j++)
		 {
		 	
		 	cout<<adj[i][j]<<"  ";
		 }
		 cout<<endl;
	}
	
}
int queue[100] ;//size of array
int front=-1;
int rear=-1;



void insert(int s)
{
	  if(rear==99)
	  {
	  	cout<<"Full";
	  	
	  }
	  else
	  {
	  	if(front==-1)
	  	{
	  		
	  		front=rear=0;
	  		queue[rear]=s;
		  }
		  else
		  {
		  	queue[++rear]=s;
		  }
		  
	  }
	
}
int del()
{
	
	if(front==rear)
	{
		int temp=queue[front];
		
		front=rear=-1;
		return temp;
	}
	else
	if(front!=-1)
	{
		return queue[front++];
	}
	else
	{
		return -45656;
	}
}
int isempty()
{
	if(front!=-1)
	{
		return 0;
	}
	else
	return 1;
}

int bfs(int s,int d)
{
	
	int visited[V]={0};
	int distance[V];
	int parent[V];
	for(int i=0;i<V;i++)
	{
		
		parent[i]=-1;
		distance[i]=INFI;
	}
	insert(s);
	distance[s]=0;
	while(!isempty())
	{
		int k=del();
		visited[k]=1;
		cout<<"\nVisited Vertex :  "<<k;
		for(int i=0;i<V;i++)
		{
			 
			if(adj[k][i]==1&&visited[i]==0)
			{
				
				insert(i);
				visited[i]=1;
				parent[i]=k;
				distance[i]=1+distance[k];
				
			}
		}
	}
	
	for(int i=0;i<V;i++)
	cout<<"\n Parent of i = "<<i<<"  is  :"<<parent[i];
	return distance[d];
}
int main()
{   

    
int maze[M][M]={{1,3,3,0},{0,3,3,3},{3,0,3,3},{2,3,3,3}};
createadj(maze);

//cout<<s<<" "<<dest<<endl;
cout<<"Distance  = "<<bfs(s,dest);	
	return 0;
	
}



