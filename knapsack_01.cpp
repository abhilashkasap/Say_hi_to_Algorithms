#include<iostream>
using namespace std;
int knapsack_01(int wt[],int n)
{
 int a[5][n+1];
 for(int i=0;i<=n;i++)
    a[0][i]=99999;
 for(int i=1;i<=4;i++)
 {

     a[i][0]=99999;
     for(int j=1;j<=n;j++)
     {

         if(wt[i-1]<=j)
         {
             if(1+ a[i-1][j-wt[i-1]]<a[i-1][j])
             {

                 a[i][j]=1+ a[i-1][j-wt[i-1]];

             }
             else
             {
                 a[i][j]=a[i-1][j];
             }
         }
         else
            a[i][j]=a[i-1][j];


         }

     }
for(int i=0;i<=4;i++)
{

for(int j=0;j<=n;j++)
    cout<<a[i][j]<<" ";
    cout<<endl;}
     return a[4][n];

 }
 int main()
 {
   int wt[]={1,5,10,25};
   
   cout<<knapsack_01(wt,37);
 }

