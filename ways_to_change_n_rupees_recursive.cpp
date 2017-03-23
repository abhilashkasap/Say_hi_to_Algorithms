#include<iostream>
using namespace std;
 
int count_number_of_ways( int coin_avail[], int m, int n )
{
   
    if (n == 0)
        return 1;
    if (n < 0)
        return 0;
    if (m <=0 && n >= 1)
        return 0;
   return count_number_of_ways(coin_avail,m-1,n)+count_number_of_ways(coin_avail,m,n-coin_avail[m-1]);
}
 

int main()
{
    int coins[]={1,5,10};
    cout<<"\n Number of ways possible = "<<count_number_of_ways(coins,3,7);
    
}
