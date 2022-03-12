// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution

{
    vector<long long> get_next_smaller(long long arr[],int n){
        
        if(n==1){
            return {1};
        }
        
        vector<long long> result(n,n);
        
        stack<long long> stk;
        
        for(int i = n;i>=0;i--){
            
            while(!stk.empty() && arr[stk.top()]>=arr[i]){
                stk.pop();
            }
            if(!stk.empty()){
                result[i] = stk.top();
            }
            stk.push(i);
        }
        
        return result;
    }
    
    vector<long long> get_prev_smaller(long long arr[],int n){
        
        if(n==1){
            return {-1};
        }
        
        vector<long long> result(n,-1);
        
        stack<long long> stk;
        
        for(int i = 0;i<n;i++){
            
            while(!stk.empty() && arr[stk.top()]>=arr[i]){
                stk.pop();
            }
            if(!stk.empty()){
                result[i] = stk.top();
            }
            stk.push(i);
        }
        
        return result;
    }
    
    public:
    //Function to find largest rectangular area possible in a given histogram.
    long long getMaxArea(long long arr[], int n)
    {
        // Your code here
        
        vector<long long> next_smaller = get_next_smaller(arr,n);
        vector<long long> prev_smaller = get_prev_smaller(arr,n);
        
        long long max_area = LLONG_MIN;
        
        for(int i = 0;i<n;i++){
            
            long long cur_area = arr[i]*(next_smaller[i]-prev_smaller[i]-1);
            
            max_area = max(max_area,cur_area);
        }
        return max_area;
    }
};


// { Driver Code Starts.

int main()
 {
    long long t;

    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        
        long long arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        Solution ob;
        cout<<ob.getMaxArea(arr, n)<<endl;
    
    }
	return 0;
}
  // } Driver Code Ends