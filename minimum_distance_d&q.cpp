#include<iostream>
#include<cmath>
#define INFI 99999
using namespace std;
float dist(int x1,int y1,int x2,int y2)
{

float distance = ((x2-x1)*(x2-x1))+((y2-y1)*(y2-y1));
distance = sqrt(distance);

return distance;
}
float find_min_dist(int a[],int x,int sx,int sy,int dx,int dy,int l,int r)
{  float min_dist;
  int mid=(l+r)/2;
  min_dist= dist(sx,sy,x,a[mid])+dist(x,a[mid],dx,dy);

  if(l==r)
  return min_dist;
  else
  {
       float upper= dist(sx,sy,x,a[mid+1])+dist(x,a[mid+1],dx,dy);
       float lower =  dist(sx,sy,x,a[mid-1])+dist(x,a[mid-1],dx,dy);
       if(lower<min_dist)
        return find_min_dist(a,x,sx,sy,dx,dy,l,mid-1);
       else
        if(upper<min_dist)
        return find_min_dist(a,x,sx,sy,dx,dy,mid+1,r);
       else
        return min_dist;
  }
}
float brute_force_app(int a[],int x,int sx,int sy,int dx,int dy,int s)
{

    float min_dist= dist(sx,sy,x,a[0])+dist(x,a[0],dx,dy);
    for(int i=0;i<s;i++)
    {

        float temp_dist = dist(sx,sy,x,a[i])+dist(x,a[i],dx,dy);
        if(temp_dist<min_dist)
            min_dist=temp_dist;
    }
    return min_dist;
}


int main()
{

    int a[5]={1,2,3,9,10};int x=5;
    int sx,sy,dx,dy;
    sx=2,sy=4,dx=7,dy=10;
    cout<<"Displaying min dist =  "<<find_min_dist(a,x,sx,sy,dx,dy,0,4);
    cout<<"\n Brute force min dist = "<<brute_force_app(a,x,sx,sy,dx,dy,5);
    return 0;
}

