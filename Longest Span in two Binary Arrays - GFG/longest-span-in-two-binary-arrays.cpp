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
        
        unordered_map<int,int> hash;
        
        vector<int> diff(2*n+1,-1);
        int sum1 = 0,sum2 = 0,cur_diff = 0,result = 0;
        
        for(int i=0;i<n;i++){
            
            sum1+=arr1[i];
            sum2+=arr2[i];
            
            cur_diff = sum1-sum2;
            
            int diff_index = cur_diff+n;
            if(cur_diff == 0){
                result = i+1;
            }
            else if(diff[diff_index]==-1){
                diff[diff_index] = i;
            }
            else{
                result = max(result,i-diff[diff_index]);
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