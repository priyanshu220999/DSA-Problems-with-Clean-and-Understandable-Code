// { Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
    
    int get_count(int m,int n,int mid){
        
        int final_count = 0;
        
        for(int i=1;i<=m;i++){
            
            int cur_count = min(mid/i,n);
            final_count +=cur_count;
        }
        return final_count;
    }
    
public:
    int KthSmallest(int m, int n, int k) {
        //Write your code here
        
        if(m==1 && n==1){
            return 1;
        }
        if(k==m*n){
            return k;
        }
        if(k==1){
            return 1;
        }
        
        int low = 1,high = m*n,result = 1;
        
        while(low<=high){
            
            int mid = (high-low)/2 + low;
            
            int cur_count = get_count(m,n,mid);
            
            if(cur_count>=k){
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
	    int m, n, k;
	    cin >> m >> n >> k;
	    Solution ob;
	    int ans = ob.KthSmallest(m, n, k);
	    cout << ans << endl;
	}
	return 0;
}
  // } Driver Code Ends