#include<iostream>
#include<cstring>
#define csize 1000
using namespace std;
int dir[csize][csize];
void print(int i,int j,char *X)
{
    if(i==0||j==0)
        return;
    else
    {

        if(dir[i][j]==0)
           {
print(i-1,j-1,X);
           cout<<X[i-1];

           }
        else
            if(dir[i][j]==1)
            print(i-1,j,X);
        else
            print(i,j-1,X);
    }
}
int lcs(char *X,char *Y)
{
   int m=strlen(X);
   int n=strlen(Y);
   int c[m+1][n+1];
   for(int i=0;i<=m;i++)
   {
    c[i][0]=0;
     dir[i][0]=0;
   }
   for(int i=1;i<=n;i++)
   {
    c[0][i]=0;
    dir[0][i]=0;

   }

   for(int i=1;i<=m;i++)
   {

       for(int j=1;j<=n;j++)
       {


           if(X[i-1]==Y[j-1]){
            c[i][j]=1+c[i-1][j-1];
            dir[i][j]=0; //diagonal
           }
           else
            if(c[i-1][j]>=c[i][j-1]){
                c[i][j]=c[i-1][j];
                dir[i][j]=1; //up
            }
                else{
                    c[i][j]=c[i][j-1];
                    dir[i][j]=2;//left
                }
           }
   }

print(m,n,X);

   return c[m][n];


}

int main()
{
char X[]="BCDRRF";
char Y[]="YYZCARGGEF";
cout<<endl;
cout<<"\n"<<lcs(X,Y);


}
