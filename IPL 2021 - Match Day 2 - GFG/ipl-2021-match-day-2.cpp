// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution {
    
    int get_max(vector<int> arr){
        
        int result = INT_MIN;
        
        for(int i:arr){
            result = max(i,result);
        }
        return result;
    }
    
  public:
    vector<int> max_of_subarrays(vector<int> arr, int n, int k) {
        // your code here
        if(k==1 || n==1){
            return arr;
        }
        if(k==n){
            return {get_max(arr)};
        }
        
        deque<int> dq;
        vector<int> result;
        
        int i=0,j=0;
        
        while(j<n){
            
            while(!dq.empty() && arr[j]>dq.back()){
                dq.pop_back();
            }
            dq.push_back(arr[j]);
            
            if(j-i+1<k){
                j++;
            }
            else if(j-i+1==k){
                
                result.push_back(dq.front());
                
                if(dq.front()==arr[i]){
                    dq.pop_front();
                }
                i++;
                j++;
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

        int n, k;
        cin >> n >> k;

        vector<int> arr(n);
        for (int i = 0; i < n; i++) cin >> arr[i];
        Solution ob;
        vector<int> res = ob.max_of_subarrays(arr, n, k);
        for (int i = 0; i < res.size(); i++) cout << res[i] << " ";
        cout << endl;
    }

    return 0;
}  // } Driver Code Ends