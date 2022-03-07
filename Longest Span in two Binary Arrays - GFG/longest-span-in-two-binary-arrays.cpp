// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution {
public:
    int longestCommonSum(bool arr1[], bool arr2[], int n) {
        // code here
        if(n==1) return arr1[0]==arr2[0]?1:0;
        
        vector<int> arr(n);
        
        for(int i=0;i<n;i++){
            arr[i] = arr1[i]-arr2[i];
        }
        
        unordered_map<int,int> hash;
        int sum = 0,result = 0;
        
        for(int i=0;i<n;i++){
            
            sum+=arr[i];
            
            if(sum==0)
                result = i+1;
            if(hash.find(sum)!=hash.end()){
                result = max(result,i-hash[sum]);
            }
            else{
                hash[sum] = i;
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
        int n, i;
        cin >> n;
        bool arr1[n], arr2[n];
        for (i = 0; i < n; i++) {
            cin >> arr1[i];
        }
        for (i = 0; i < n; i++) {
            cin >> arr2[i];
        }
        Solution ob;
        auto ans = ob.longestCommonSum(arr1, arr2, n);
        cout << ans << "\n";
    }
    return 0;
}  // } Driver Code Ends