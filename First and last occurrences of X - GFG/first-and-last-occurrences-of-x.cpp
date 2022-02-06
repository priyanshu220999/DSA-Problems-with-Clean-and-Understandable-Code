// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
    
    int first_occurence(vector<int> nums,int n,int target){
        
        int result = -1;
        
        int low = 0,high = n-1;
        
        while(low<=high){
            
            int mid = (low+high)/2;
            
            int cur_element = nums[mid];
            
            if(cur_element == target){
                result = mid;
                high = mid-1;
            }
            else if(cur_element < target){
                low = mid+1;
            }
            else{
                high = mid-1;
            }
            
        }
        return result;
    }
    
    int last_occurence(vector<int> nums,int n,int target){
        
        int result = -1;
        
        int low = 0,high = n-1;
        
        while(low<=high){
            
            int mid = (low+high)/2;
            
            int cur_element = nums[mid];
            
            if(cur_element == target){
                result = mid;
                low = mid+1;
            }
            else if(cur_element < target){
                low = mid+1;
            }
            else{
                high = mid-1;
            }
            
        }
        return result;
    }
    
  public:
    vector<int> firstAndLast(vector<int> &arr, int n, int x) {
        // Code here
        
        // vector<int> result;
        
        if(n==1){
            if(arr[0]==x)
                return {0,0};
            return {-1};
        }
        
        int first_occur = first_occurence(arr,n,x);
        int last_occur = last_occurence(arr,n,x);
        
        if(first_occur==-1) return {-1};
        
        return {first_occur,last_occur};
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        Solution obj;
        vector<int> ans= obj.firstAndLast(arr, n, x) ;
        for(int i:ans){
            cout<<i<<" ";
        }
        cout<< endl;
    }
    return 0;
}
  // } Driver Code Ends