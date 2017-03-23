#include<iostream>
using namespace std;
int n;
void print(int i,int j)
{

    if(i==j)
        cout<<i<<" ";
    else
    {
        for(int k=i;k<j;k++){

        cout<<"( ";
        print(i,k);
        print(k+1,j);
        cout<<" )";

    }

    }
}

int main()
{


    print(1,4);
}
