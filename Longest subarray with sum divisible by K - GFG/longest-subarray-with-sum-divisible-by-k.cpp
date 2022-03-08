// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

 // } Driver Code Ends
//User function template for C++
class Solution{
public:	
	int longSubarrWthSumDivByK(int arr[], int n, int k)
	{
	    // Complete the function
	    if(n==1){
	        return arr[0]%k==0?1:0;
	    }
	    
	    int result = 0;
	    long int sum = 0;
	    unordered_map<int,int> hash;
	    
	    for(int i = 0;i<n;i++){
	        
	        sum+=arr[i];
	        
	        if(((sum%k)+k)%k==0){
	            result = i+1;
	        }
    	    else if(hash.find(((sum%k)+k)%k)!=hash.end()){
    	        result = max(result,i-hash[((sum%k)+k)%k]);
    	    }
    	    else{
    	        hash[((sum%k)+k)%k] = i;
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
	int n,k,i;
	cin>>n>>k; int arr[n];
	for(i=0;i<n;i++)
	cin>>arr[i];
	Solution ob;
	cout<<ob.longSubarrWthSumDivByK(arr, n, k)<<"\n";
	}
	return 0;	 
}
  // } Driver Code Ends