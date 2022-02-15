// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
    
    bool is_even(long long int n){
        return n%2==0;
    }
    
	public:
		long long int PowMod(long long int x,long long int n,long long int M)
		{
		    // Code here
		    if(n==1)
		        return x%M;
		    if(n==0)
		        return 1;
		    
		    if(is_even(n)){
		        long long int half_sqr = PowMod(x,n/2,M)%M;
		        return (half_sqr*half_sqr)%M;
		    }
		    else{
		        long long int half_sqr = PowMod(x,n-1,M)%M;
		        return (half_sqr*(x%M))%M;
		    }
		    return 0;
		}
};

// { Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	long long int x, n, m;
    	cin >> x >> n >> m;
    	Solution ob;
    	long long int ans = ob.PowMod(x, n, m);
    	cout << ans <<"\n";
    }
	return 0;
}
  // } Driver Code Ends