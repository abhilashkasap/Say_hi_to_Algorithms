#include<stdio.h>
void main()
{
  int i,j;
    int a[5];
    printf("Enter Values in arrray :");
    for(i=0;i<5;i++)
      scanf("%d",&a[i]);
   printf("Printing Addresses :");
   for(j=0;j<5;j++)
    printf("%d ", &a[j]);


}
