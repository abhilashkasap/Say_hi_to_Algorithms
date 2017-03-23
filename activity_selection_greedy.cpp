#include<iostream> //greedy approach
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

void activity_selection(activity array[],int size)
{

    activity sarray[100]={0};
     sarray[0]=array[0];
     int index=0;int c=0;
     for(int i=1;i<size;i++)
     {

         if(array[i].st>=array[index].ft)
         {

             sarray[++c]=array[i];
             index=i;
         }

     }

     cout<<"\n Printing selected activities :-";
     cout<<endl;
     for(int i=0;i<=c;i++)
     {

         cout<<sarray[i].st<<endl;
         cout<<sarray[i].ft<<endl;
         cout<<endl;
     }

}

int main()
{


    activity array[]={{1,5},{4,5},{3,5},{7,8},{6,9},{9,10}};
    sort(array,0,5);
    activity_selection(array,6);
}
