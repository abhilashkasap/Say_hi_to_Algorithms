#include<iostream>
using namespace std;
int linearsearch(int a[],int data,int s)
{
   int i;

    int flag;
    flag=0;
    for(i=0;i<s;i++)
        if(a[i]==data)
       {

        flag=1;
        break;
       }
   if(flag==1)
    return i;
   else
    return -1;

}
int binarysearch(int a[],int data,int l,int r)
{

   int mid=(l+r)/2;
   if(a[mid]==data)
   {
       return mid;

   }
   else
    if(a[mid]!=data&&l>=r)
   {
       return -1;
   }
   else
   {

       if(data>a[mid])
        return binarysearch(a,data,mid+1,r);
       else
        return binarysearch(a,data,l,mid-1);
   }



}

int trinarysearch(int a[],int data,int l,int r)
{


    
    int mid1=l+ ((r-l+1)/3);
    int mid2= l + ((r-l+1)*2/3);
    if(data==a[mid1])
        return mid1;
    else
        if(data==a[mid2])
        return mid2;
    else
        if(l==r&&a[l]==data)
        return l;
        else
            if(l>=r)
            return -1;
    else
    {
        if(data>a[mid1])
        {
            if(data>a[mid2])
            {
                return trinarysearch(a,data,mid2+1,r);
            }
            else
                return trinarysearch(a,data,mid1+1,mid2-1);

        }
        else
        {
            return trinarysearch(a,data,l,mid1-1);
        }

    }

}
int main()
{


    int a[8]={1,2,3,4,5,6,7,8};int data;
    
    cout<<"Enter Element to be searched = ";cin>>data;
    cout<<" Linear search result :"<<linearsearch(a,data,8)<<endl;
    cout<<" Binary Search result :"<<binarysearch(a,data,0,7)<<endl;
    cout<<" Trinary Search result :"<<trinarysearch(a,data,0,7)<<endl;
    return 0;

}
