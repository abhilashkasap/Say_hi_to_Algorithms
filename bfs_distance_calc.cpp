#include<iostream>//simple bfs with distance calc
using namespace std;
#define N 5
#define INFI 99999

int queue[100] ;//size of array
int front=-1;
int rear=-1;

int a[N][N]={{0,0,1,0,1},
                    {0,0,1,1,1},
                    {1,1,0,0,1},
                    {0,1,0,0,1},
                    {1,1,1,1,0}};

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
	
	int visited[N]={0};
	int distance[N];
	int parent[N];
	for(int i=0;i<N;i++)
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
		for(int i=0;i<N;i++)
		{
			 
			if(a[k][i]==1&&visited[i]==0)
			{
				
				insert(i);
				visited[i]=1;
				parent[i]=k;
				distance[i]=1+distance[k];
				
			}
		}
	}
	
	for(int i=0;i<N;i++)
	cout<<"\n Parent of i = "<<i<<"  is  :"<<parent[i];
	return distance[d];
}
int main()
{
	cout<<"\n Distance = "<<bfs(0,1);
	
	return 0;
	
}

