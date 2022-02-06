// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


 // } Driver Code Ends
//User function template for C++
class Solution{
    
    bool is_sorted(int arr[],int left,int right){
        return arr[left]<=arr[right];
    }
    
public:	
	int findKRotation(int arr[], int n) {
	    // code here
	    
	    int left = 0,right = n-1;
	    
	    while(left<=right){
	        
	        if(arr[left]<=arr[right])
	            return left;
	        
	        int mid = (left+right)/2;
	        
	        int next = (mid+1)%n;
	        int prev = (mid-1+n)%n;
	        
	        if(arr[next]>=arr[mid] && arr[prev]>=arr[mid])
	            return mid;
	        else if(is_sorted(arr,left,mid))
	            left = mid+1;
	        else if(is_sorted(arr,mid,right))
	            right = mid-1;
	    }
	    return 0;
	}

};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findKRotation(a, n);
        cout << ans << "\n";
    }
    return 0;
}
  // } Driver Code Ends