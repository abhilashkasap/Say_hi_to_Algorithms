#include<iostream> //dynamic way
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
int c[size][size];
for(int i=0;i<size;i++)
    c[i][i]=0;

    for(int d=1;d<=size-1;d++)
{

    for(int i=0;i<size-d;i++)
    {

        int j=i+d;
        int max=-1;
        if(array[j].st<array[i].ft)
            c[i][j]=0;
        else{
        for(int k=i+1;k<j;k++)
            if((c[i][k]+1+c[k+1][j])>max)
                max=c[i][k]+1+c[k][j];
            c[i][j]=max;
    }
}
}
cout<<" Maximum selected activities = "<<c[0][size-1];
}
int main()
{


    activity array[]={{1,3},{2,5},{4,8},{5,10},{9,13}}; //input 
    activity_selection(array,5);
}
