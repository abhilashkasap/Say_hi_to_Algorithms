#include<stdio.h>
void main()
{

    int a[5];
    int i,j;
    for(i=0;i<5;i++)
        scanf("%d",&a[i]);
   printf("Enter no of times you want to rotate :");
   int d;
   scanf("%d",&d);
   while(d>0)
   {

          int temp =a[0];
          for(i=1;i<5;i++)
          {

              a[i-1]=a[i];
          }
          a[4]=temp;
          d--;

   }
   printf("After d rotation ");
   for(i=0;i<5;i++)
    printf("%d ", a[i]);
}
