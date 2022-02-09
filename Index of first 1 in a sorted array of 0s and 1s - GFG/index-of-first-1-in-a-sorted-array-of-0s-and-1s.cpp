// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
    public:
    int firstIndex(int a[], int n) 
    {
        // Your code goes here
        
        if(n==1){
            if(a[0]==1)
                return 0;
            return -1;
        }
        
        if(a[n-1]==0)
            return -1;
            
        int left = 0,right = n-1;
        
        int result = -1;
        
        while(left<=right){
            
            int mid = (left+right)/2;
            
            int cur_element = a[mid];
            
            if(cur_element == 1){
                result = mid;
                right = mid-1;
            }
            else if(cur_element == 0){
                left = mid+1;
            }
        }
        return result;
    }
};

// { Driver Code Starts.
int main() {

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        int a[n];

        for (int i = 0; i < n; i++) cin >> a[i];
        Solution ob;
        cout << ob.firstIndex(a, n) << endl;
    }
}  // } Driver Code Ends