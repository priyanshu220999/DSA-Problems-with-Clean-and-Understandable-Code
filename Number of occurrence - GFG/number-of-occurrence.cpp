// { Driver Code Starts


#include<bits/stdc++.h>

using namespace std;


 // } Driver Code Ends
//User function template for C++
class Solution{
    
    int left_occurence(int arr[],int n,int target){
        
        int result = -1;
        
        int left = 0,right = n-1;
        
        while(left<=right){
            
            int mid = (left+right)/2;
            
            if(arr[mid]==target){
                result = mid;
                right = mid-1;
            }
            else if(arr[mid]<target){
                left = mid+1;
            }
            else
                right = mid-1;
            
        }
        return result;
    }
    
    int right_occurence(int arr[],int n,int target){
        
        int result = -1;
        
        int left = 0,right = n-1;
        
        while(left<=right){
            
            int mid = (left+right)/2;
            
            if(arr[mid]==target){
                result = mid;
                left = mid+1;
            }
            else if(arr[mid]<target){
                left = mid+1;
            }
            else
                right = mid-1;
            
        }
        return result;
    }
    
public:	
	/* if x is present in arr[] then returns the count
		of occurrences of x, otherwise returns 0. */
	int count(int arr[], int n, int x) {
	    // code here
	    
	    if(n==1){
	        return arr[0]==x?1:0;
	    }
	    
	    int count = 0;
	    
	    int left_occur = left_occurence(arr,n,x);
	    
	    if(left_occur==-1) return 0;
	    
	    int right_occur = right_occurence(arr,n,x);
	    
	    count = (right_occur-left_occur+1);
	    
	    return count;
	}
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.count(arr, n, x);
        cout << ans << "\n";
    }
    return 0;
}
  // } Driver Code Ends