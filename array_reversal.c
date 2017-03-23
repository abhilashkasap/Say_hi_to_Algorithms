#include<stdio.h>
void main()
{

    int a[5];
    int i;
    for(i=0;i<5;i++)
        scanf("%d",&a[i]);
   int temp[5];
   for(i=4;i>=0;i--)
    temp[i]=a[4-i];
    for(i=0;i<5;i++)
        a[i]=temp[i];
        for(i=0;i<5;i++)
        printf("%d ",a[i]);
}
