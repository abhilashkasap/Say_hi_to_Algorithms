#include<iostream>
using namespace std;
int n;
int p(int k)
{
    int sum=0;
    if(k==1||k==2)
        return 1;
    else
    {
        for(int i=1;i<=k-1;i++)
            sum=sum+ (p(i)*p(k-i));
        return sum;
    }

}

int main()
{


    cout<<p(5);
}
