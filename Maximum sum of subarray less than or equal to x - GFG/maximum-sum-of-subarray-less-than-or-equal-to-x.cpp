// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{


	public:
	int findMaxSubarraySum(long long arr[], int n, long long sum)
	{
	    // Your code goes here
	    
	    if(n==1)
	        return arr[0]<=sum?arr[0]:0;
	    
	    long long result = 0,cur_sum = 0;
	    int i = 0,j = 0;
	    
	    while(j<n){
	        
	        cur_sum +=arr[j];
	        
	        if(cur_sum<=sum){
	            result = max(cur_sum,result);
	        }
	        else{
	            
	            while(cur_sum>sum){
	                
	                cur_sum-=arr[i++];
	                
	                if(cur_sum<=sum){
	                    result = max(result,cur_sum);
	                }
	            }
	        }
	        j++;
	    }
	    return result;
	}
};
	  



// { Driver Code Starts.

int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
    	 int n;
        cin>>n;
        
        long long a[n];
        for(int i=0; i<n; i++)
            cin>>a[i];
        
        long long sum;
        cin >> sum;
        

        Solution ob;
		cout << ob.findMaxSubarraySum(a, n, sum);
        
	    cout << "\n";
	     
    }
    return 0;
}  // } Driver Code Ends