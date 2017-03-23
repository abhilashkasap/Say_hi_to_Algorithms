#include<iostream>//simple bfs without distance calc
using namespace std;
#define N 5


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

void bfs(int s)
{
	
	int visited[N]={0};
	int parent[N]={-1,-1,-1,-1,-1}; //change a/c to N
	insert(s);
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
				
			}
		}
	}
	
	for(int i=0;i<N;i++)
	cout<<"\n Parent of i = "<<i<<"  is  :"<<parent[i];
}
int main()
{
	bfs(0);
	
	return 0;
	
}

