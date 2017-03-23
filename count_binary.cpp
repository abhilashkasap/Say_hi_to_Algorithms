#include<iostream>
using namespace std;

static int count;
int binarySearch(int *arr,int val,int n)
{

    
    int beg = 0;
    int end = n-1;
    int mid;

    while(beg <= end){
    	
        mid = (beg+end)/2;
        
        if(val == arr[mid]){
            count++;
            
            for(int i=mid-1;i>=0;i--)
            if(val==arr[i])
            count++;
            for(int i=mid+1;i<n;i++)
            if(val==arr[i])
            count++;
            break;
            
        
        }
        else if(val > arr[mid]){
            beg = mid+1;
        }
        else if(val < arr[mid]){
            end = mid-1;
        }
    }
    
    
    
    return count;
}

int main()
{
    int n,q,val;
    cin >> n;

    int arr[n];
    for(int i = 0;i < n;i++){
        cin >> arr[i];
    }
    
    cin >> q;
    int arrVal[q];
    
    int j=0;
    while(j<q)
    {
        cin>>arrVal[j++];
        
    }
    

    for(int i = 0;i < q;i++){
    	
        val = arrVal[i];
        int count = binarySearch(arr,val,n);
        
        if(count >= n/4){
            cout << "Yes" <<endl;
        }
        else{
            cout << "No" <<endl;
        }
    }

    return 0;
}
