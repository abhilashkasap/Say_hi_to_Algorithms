#include<iostream> //find connected component
#include<cstdlib>
using namespace std;
#define MAX 100
int disjoint[MAX][2];
int size=0;
void makeset(int vertex)
{
    disjoint[vertex][0]=vertex; //assigning vertex number
    disjoint[vertex][1]=vertex; //assigning set representative
    size++;
    cout<<"\n One new set created !!";



}
int findset(int vertex)
{

     return disjoint[vertex][1];

}
void unionset(int v1,int v2)
{

    int v1_r=findset(v1);
    int v2_r=findset(v2);

    if(v1_r!=v2_r)
    {
        for(int i=1;i<=size;i++)
            if(disjoint[i][1]==v2_r)
        disjoint[i][1]=v1_r;
    }
    cout<<"\n Union of two vertex is done ";

}
void seesets()
{
    cout<<"\n vertices and their representatives \n";
    for(int i=1;i<=size;i++)
    {

        cout<<"Vertex Number     :"<<disjoint[i][0]<<endl;
        cout<<"Set Representative:"<<disjoint[i][1]<<endl;
    }
}
void find_connected(int V[],int adj[][7],int size)
{


    for(int i=0;i<size;i++)
        makeset(V[i]);
    for(int i=1;i<=size;i++)
    {

        for(int j=1;j<=size;j++)
        {

            if(adj[i][j]==1)
            {


                if(findset(i)!= findset(j))
                    unionset(i,j);
            }
        }
    }
}

int main()
{

    int V[]={1,2,3,4,5,6};
    int adj[7][7]={0};
    //edges
    adj[1][2]=1;
    adj[2][1]=1;
    adj[1][4]=1;
    adj[4][1]=1;
    adj[5][6]=1;
    adj[6][5]=1;
    find_connected(V,adj,6);
    seesets();
    return 0;

}

