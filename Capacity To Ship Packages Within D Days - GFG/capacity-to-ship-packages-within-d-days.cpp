// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution {
    
    void find_max_and_sum(int arr[],int n,int &maxi,int &sum){
        
        for(int i=0;i<n;i++){
            
            sum+=arr[i];
            
            if(arr[i]>maxi){
                maxi = arr[i];
            }
        }
    }
    
    bool is_valid_capacity(int arr[],int n,int d,int limit){
        
        int cur_days = 1;
        
        int weight = 0;
        
        for(int i=0;i<n;i++){
            
            if(arr[i]>limit){
                return false;
            }
            else if(arr[i]+weight>limit){
                cur_days++;
                weight = arr[i];
                
                if(cur_days>d){
                    return false;
                }
            }
            else{
                weight+=arr[i];
            }
        }
        return true;
    }
    
  public:
    int leastWeightCapacity(int arr[], int n, int d) {
        // code here
        
        if(n==1){
            return arr[0];
        }
        
        int max_weight = INT_MIN;
        
        int tot_weight = 0;
        
        find_max_and_sum(arr,n,max_weight,tot_weight);
        
        if(d==1){
            return tot_weight;
        }
        
        int low = max_weight,high = tot_weight;
        
        int result = -1;
        
        while(low<high){
            
            int mid = (high-low)/2 + low;
            
            if(is_valid_capacity(arr,n,d,mid)){
                result = mid;
                high = mid;
            }
            else{
                low = mid+1;
            }
        }
        return result;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N,D;
        cin>>N;
        
        int arr[N];
        for(int i=0; i<N; i++)
            cin>>arr[i];
        cin>>D;

        Solution ob;
        cout << ob.leastWeightCapacity(arr,N,D) << endl;
    }
    return 0;
}  // } Driver Code Ends