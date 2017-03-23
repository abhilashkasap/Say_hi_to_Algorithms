#include<iostream> //using recursive way
using namespace std;
struct activity
{

    int st;
    int ft;
};
void swap(activity &ob1,activity &ob2)
{
    activity ob3=ob1;
    ob1=ob2;
    ob2=ob3;


}
void sort(activity array[],int l,int r)
{
   if(l>=r)
    return ;
   else
   {


       int pivot = l;
       int lower= l;
       for(int i=lower+1;i<=r;i++)
       {

          if(array[i].ft<array[pivot].ft)
          {
              swap(array[i],array[lower+1]);
              lower++;

          }

       }

       swap(array[pivot],array[lower]);
       sort(array,l,lower-1);
       sort(array,lower+1,r);
   }



}
void activity_selection(activity array[], int size)
{
int c[size][size]={0};

for(int i=0;i<size;i++)
{
	
	for(int j=0;j<size;j++)
	{
		
	      if(array[i].ft>array[j].st)
	      c[i][j]=0;
	      else
	      {
	      	
	      	int max=0;
	      	for(int k=i+1;k<j;k++)
	      	if((c[i][k]+1+c[k][j])>max)
	      	max=c[i][k]+1+c[k][j];
	      	c[i][j]=max;
		  }
	}
}

for(int i=0;i<size;i++)
{

    for(int j=0;j<size;j++)
        cout<<c[i][j]<<"   ";
    cout<<endl;
}
}
int main()
{


    activity array[]={{1,3},{4,5},{5,8},{8,10},{1,13}};
    sort(array,0,4);
    for(int i=0;i<5;i++)
    {
    	
    	cout<<array[i].st<<endl;
    	cout<<array[i].ft<<endl;
    	cout<<endl;
	}
    activity_selection(array,5);
}
