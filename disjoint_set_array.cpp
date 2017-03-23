#include<iostream> // disjoint-sets data structure using array+ connected component of graph
using namespace std;
int disjoint[100][2]; // disjoint[][0] = vertex number and disjoint[][1]= set representative 
int size=0;
void makeset(int vertex_number)
{
	
     disjoint[vertex_number][0]=vertex_number;
	 disjoint[vertex_number][1]=vertex_number;
	 cout<<" A set created for the given vertex number "<<endl;
	 size++;
}
int findset(int vertex_number)
{
	
	return disjoint[vertex_number][1];
}
void unionset(int v1,int v2)
{
	
	int v1_r = disjoint[v1][1];
	int v2_r = disjoint[v2][1];
	
	if(v1_r != v2_r)
	{
		for(int i=1;i<=size;i++)
		{
			
			if(disjoint[i][1]==v2_r)
			disjoint[i][1]=v1_r;
		}
		
	}
	
	cout<<"\n Union Operation completed !!";
	
}

void connected_comp(int V[],int size,int adj[][11])
{
	
	for(int i=0;i<size;i++)
	makeset(V[i]);
	for(int i=1;i<=size;i++)
	{
		
		for(int j=1;j<=size;j++)
		{
			
			if(adj[i][j]==1)
			{
				
				if(findset(i)!=findset(j))
				{
					unionset(i,j);
				}
			}
		}
	}
}

int main()
{
	
	int V[]={1,2,3,4,5,6,7,8,9,10};
	int adj[11][11]={0};
	adj[1][2]=1;
	adj[2][1]=1;
	adj[1][3]=1;
	adj[1][4]=1;
	adj[4][1]=1;
	adj[5][6]=1;
	adj[6][5]=1;
	adj[5][7]=1;
	adj[7][5]=1;
	adj[8][9]=1;
	adj[9][8]=1;
	
/*	for(int i=0;i<10;i++)
	makeset(V[i]);
     unionset(2,3);
     unionset(3,4);
     unionset(1,2);*/
     
     connected_comp(V,10,adj);
    for(int i=1;i<=size;i++)
    {
    	
    	cout<<" Set "<<i<<" Details :";
    	cout<<"\n Vertex number : "<<disjoint[i][0];
    	cout<<"\n Set representative :"<<disjoint[i][1];
    	cout<<endl;
	}
	
	
	return 0;
}

