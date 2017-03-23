#include<iostream> //disjoint set data structure using array
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
int main()
{


    while(1)
    {


        int c;
        cout<<" Disjoint-set data structure "<<endl;
        cout<<" \n1. Make set \n2.Find set \n3.Union Set \n4.See Set positions \n5.Exit";
        cout<<endl;
        cout<<"\n Enter Choice :";
        cin>>c;
        switch(c)
        {
           case 1: { cout<<"\n Enter Vertex";
           int data;
           cin>>data;
           makeset(data);
           break;
           }
           case 2: { cout<<"\n Enter Vertex";
           int data;
           cin>>data;
           cout<<"\n Set Representative :"<<findset(data);
           break;
           }
           case 3: { cout<<"\n Enter verices :";
           int v1,v2;
           cin>>v1>>v2;
           unionset(v1,v2);
           break;
           }
           case 4:{
               seesets();
               break;
           }
           case 5: exit(0);


        }
    }
}
