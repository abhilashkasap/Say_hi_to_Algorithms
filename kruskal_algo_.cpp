#include<iostream> //kruskal algorithm
#include<cstdlib>
using namespace std;
#define MAX 100
#define N 5  //predefined number of nodes
#define INFI 999999
/*struct arr
{

        int s;
        int d;
        int w;
};*/
int adjacanet[7][3];
void seesets();
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
        for(int i=0;i<size;i++)
            if(disjoint[i][1]==v2_r)
        disjoint[i][1]=v1_r;
    }

    cout<<"\n Union of two vertex is done ";

}
void seesets()
{
    cout<<"\n vertices and their representatives \n";
    for(int i=0;i<=size;i++)
    {

        cout<<"Vertex Number     :"<<disjoint[i][0]<<endl;
        cout<<"Set Representative:"<<disjoint[i][1]<<endl;
    }
}

void kruskal()
{
    int ed[N][2]={0};
    int c=0;

    for(int i=0;i<N;i++)
        makeset(i);
   for(int i=0;i<7;i++)
   {


       if(findset(adjacanet[i][0])!=findset(adjacanet[i][1]))
        {

            unionset(adjacanet[i][0],adjacanet[i][1]);
            ed[c][0]=adjacanet[i][0];
            ed[c][1]=adjacanet[i][1];
            c++;
            }
       }

    for(int i=0;i<c;i++)
    {
        cout<<endl<<ed[i][0]<<" "<<ed[i][1];
    }




}
int main()
{
adjacanet[0][0]=0;adjacanet[0][1]=2;adjacanet[0][2]=1;
adjacanet[1][0]=2;adjacanet[1][1]=4;adjacanet[1][2]=1;
adjacanet[2][0]=1;adjacanet[2][1]=3;adjacanet[2][2]=2;
adjacanet[3][0]=3;adjacanet[3][1]=4;adjacanet[3][2]=3;
adjacanet[4][0]=1;adjacanet[4][1]=4;adjacanet[4][2]=5;
adjacanet[5][0]=1;adjacanet[5][1]=2;adjacanet[5][2]=5;
adjacanet[6][0]=0;adjacanet[6][1]=4;adjacanet[6][2]=15;
kruskal();
return 0;

}
