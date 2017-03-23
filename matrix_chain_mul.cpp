#include<iostream> // matrix chain and printing parenthesis
using namespace std;
#define INFI 99999
#define csize 1000
int b[csize][csize];
void print(int i,int j)
{
    if(i==j)
    cout<<i;
    else
    {

        cout<<"(";
        print(i,b[i][j]);
        print(b[i][j]+1,j);
        cout<<")";
    }

}
int mcm(int sm[],int sz)
{

    int n= sz-1;
    int m[sz][sz];
    for(int i=0;i<sz;i++)
        m[i][i]=0;

    for(int d=1;d<=n-1;d++)
    {

        for(int i=1;i<=n-d;i++)
        {

            int j=i+d;
            m[i][j]=INFI;
            for(int k=i;k<j;k++)
            {

                int temp;
                temp= m[i][k]+m[k+1][j]+sm[i-1]*sm[k]*sm[j];
                if(temp<m[i][j]){
                    m[i][j]=temp;
                    b[i][j]=k;}
            }

        }
    }
print(1,n);
    return m[1][n];

}

int main()
{


    int sm[]={10,20,50,1,100};
    cout<<"\n"<<mcm(sm,5);
    return 0;
}
