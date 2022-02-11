// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


 // } Driver Code Ends
//User function template for C++
class Solution{
public:
	
	int findMaximum(int arr[], int n) {
	    // code here
	    
	    if(arr[n-1]>=arr[n-2]) return arr[n-1];
	    
	    if(n==3){
	        return arr[2]>=arr[1]?arr[2]:arr[1];
	    }
	    
	    int low = 0,high = n-1;
	    
	    while(low<=high){
	        
	        int mid = (low+high)/2;
	        
	        int cur_ele = arr[mid];
	        
	        int next_ele = mid+1<n?arr[mid+1]:-1;
	        
	        int prev_ele = mid-1>=0?arr[mid-1]:-1;
	        
	        if(cur_ele>prev_ele && cur_ele>next_ele)
	            return cur_ele;
	        else if(cur_ele<next_ele)
	            low = mid+1;
	        else
	            high = mid-1;
	    }
	    
	    return -1;
	}
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.findMaximum(arr, n);
        cout << ans << "\n";
    }
    return 0;
}
  // } Driver Code Ends