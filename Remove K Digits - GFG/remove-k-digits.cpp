// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    string removeKdigits(string s, int k) {
        
        int n = s.size();
        
        if(n==1 || k==n){
            return "0";
        }
        
        string result = "";
        stack<int> stk;
        
        for(int i=0;i<n;i++){
            
            while(!stk.empty() && stk.top()>s[i] && k){
                stk.pop();
                k--;
            }
            if((stk.empty() && s[i]!='0') || !stk.empty()){
                stk.push(s[i]);
            }
        }
        
        while(!stk.empty() && k){
            stk.pop();
            k--;
        }
        
        if(stk.empty()) return "0";
        
        while(!stk.empty()){
            result += stk.top();
            stk.pop();
        }
        
        reverse(result.begin(),result.end());
        
        return result;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;
        int K;
        cin >> K;
        Solution obj;
        cout << obj.removeKdigits(S, K) << endl;
    }
    return 0;
}
  // } Driver Code Ends