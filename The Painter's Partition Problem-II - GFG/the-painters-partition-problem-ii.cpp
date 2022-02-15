// { Driver Code Starts
// driver code

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++

class Solution
{
    void find_max_and_total(int arr[],int n,long long int &maxi,long long int &sum){
        
        for(int i=0;i<n;i++){
            
            sum+=arr[i];
            if(arr[i]>maxi){
                maxi = arr[i];
            }
        }
    }
    
    bool is_valid(int arr[],int n,long long limit,int k){
        
        int cur_time = 0;
        
        int painters = 1;
        
        for(int i = 0;i<n;i++){
            
            if(arr[i]>limit) return false;
            
            else if(arr[i]+cur_time>limit){
                painters++;
                cur_time = arr[i];
                if(painters>k)
                    return false;
            }
            else{
                cur_time += arr[i];
            }
        }
        return true;
    }
    
  public:
    long long minTime(int arr[], int n, int k)
    {
        // code here
        // return minimum time
        
        if(n==1) return arr[0];
        
        long long int max_len = INT_MIN,tot_len = 0;
        
        find_max_and_total(arr,n,max_len,tot_len);
        
        long long low = max_len,high = tot_len,result = 1;
        
        while(low<=high){
            
            long long mid = (high-low)/2 + low;
            
            if(is_valid(arr,n,mid,k)){
                result = mid;
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return result;
    }
};

// { Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int k,n;
		cin>>k>>n;
		
		int arr[n];
		for(int i=0;i<n;i++)
		    cin>>arr[i];
		Solution obj;
		cout << obj.minTime(arr, n, k) << endl;
	}
	return 0;
}  // } Driver Code Ends