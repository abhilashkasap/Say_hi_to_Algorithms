#include<iostream>

using namespace std;
void swap(float &a,float &b)
{

    float temp=a;
    a=b;
    b=temp;
}
void sort(float a[],float wt[],float profit[],int size)
{
    for(int i=0;i<size;i++)
    {

        for(int j=0;j<size-1;j++)
        {

            if(a[j]<a[j+1])
            {
                swap(a[j],a[j+1]);
                swap(wt[j],wt[j+1]);
                swap(profit[j],profit[j+1]);
            }
        }
    }


}

float frac_knapsack(float weight[],float profit[],float ratio[],int n,float maxweight)
{

   float x[n];
   float w=0; int i=0;
   while(w<maxweight)
   {


       if(w+weight[i]<=maxweight)
       {

           x[i]=1;
           w=w+weight[i];
           i++;
           cout<<"1";
       }
       else
       {   float temp=maxweight-w;
       temp=temp/weight[i];
       cout<<temp<<endl;
           x[i]= temp;
           w=maxweight;

       }
   }
   float p=0;
   for(i=0;i<n;i++)
   p+=(x[i]*profit[i]);

   return p;
}
int main()
{

  float a[]={2.0,1.5,2.2,1.0,1.2};
  float wt[]={10,20,30,40,50};
  float profit[]={20,30,66,40,60};

  sort(a,wt,profit,5);

  for(int i=0;i<5;i++)
    cout<<a[i]<<" "<<wt[i]<<" ";
  cout<<"Max Profit ="<<frac_knapsack(wt,profit,a,5,100);

}
