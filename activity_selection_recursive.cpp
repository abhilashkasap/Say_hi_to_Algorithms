#include<iostream> //recursive activity selection
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

int recursive_as(activity array[],int i,int j)
{
	
	if(array[j].ft<=array[i].ft)
	{
	
	return 0;
	
}
	else
	{
		
		int m=i+1;
		for( ;array[m].ft<array[j].ft;m++)
		 {
		 	if(array[m].st>=array[i].ft)
		 	break;
		 }
		 
		 return 1+recursive_as(array,m,j);
	}
}

int main()
{


    activity array[]={{1,3},{4,5},{3,8},{8,10},{1,13}};//choose desired input here
    sort(array,0,4);
    
    cout<<"Maximum number of activities selected = "<<recursive_as(array,0,4);
}
