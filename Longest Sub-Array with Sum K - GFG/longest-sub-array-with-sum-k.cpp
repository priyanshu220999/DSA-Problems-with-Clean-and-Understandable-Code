// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends

class Solution{
    public:
    int lenOfLongSubarr(int A[],  int N, int k) 
    { 
        // Complete the function
        unordered_map<int,int> hash;
        
        int sum = 0,max_length = 0;
        
        for(int i=0;i<N;i++){
            
            sum+=A[i];
            
            if(sum==k){
                max_length = i+1;
            }
            
            if(hash.find(sum)==hash.end())
                hash[sum] = i;
                
            if(hash.find(sum-k)!=hash.end()){
                max_length = max(max_length,i-hash[sum-k]);
            }
        }
        return max_length;
    } 

};

// { Driver Code Starts.

int main() {
	//code
	
	int t;cin>>t;
	while(t--)
	{
	    int n, k;
	    cin>> n >> k;
	    int a[n];
	    
	    for(int i=0;i<n;i++)
	        cin>>a[i];
	   Solution ob;
	   cout << ob.lenOfLongSubarr(a, n , k)<< endl;
	    
	}
	
	return 0;
}  // } Driver Code Ends