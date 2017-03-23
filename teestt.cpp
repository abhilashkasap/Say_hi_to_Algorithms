#include <iostream>


using namespace std;

int gcdr(int a, int b )
{
  if ( a==0 ) 
   return b;
  return gcdr(b%a, a );
}

int main(){
    int n;
    int m;
    int q;
    cin >> n >> m >> q;
    int a[n];
    for(int a_i = 0; a_i < n; a_i++){
       cin >> a[a_i];
    }
    int b[m];
    for(int b_i = 0; b_i < m; b_i++){
       cin >> b[b_i];
    }
    for(int a0 = 0; a0 < q; a0++){
        int r1;
        int c1;
        int r2;
        int c2;
        cin >> r1 >> c1 >> r2 >> c2;
        // your code goes here
        int k[n][m];
        for(int i=0;i<n;i++)
            {
            
            for(int j=0;j<m;j++)
                {
                k[i][j]=gcdr(a[i],b[j]);
            }
        }
        
        int hash[50]={0};
        for(int i=r1-1;i<r2;i++)
            {
            
            for(int j=c1-1;j<c2;j++)
                {
                hash[k[i][j]]++;
                cout<<k[i][j]<<" ";
            }
        }
        int count=0;
        for(int i=0;i<50;i++)
            if(hash[i]==1)
            count++;
        
            
            cout<<count;
    }
    return 0;
}
