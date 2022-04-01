// { Driver Code Starts
// Initial template for C++
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for c++
class Solution {
    
    bool is_open(char b){
        return b=='(';
    }
  public:
    int findMaxLen(string s) {
        // code here
        
        int n = s.size();
        
        if(n==1){
            return 0;
        }
        
        stack<int> stk;
        stk.push(-1);
        int result = 0;
        for(int i=0;i<n;i++){
            
            if(is_open(s[i])){
                stk.push(i);
            }
            else{
                if(!stk.empty() && stk.top()==-1){
                    stk.pop();
                    stk.push(i);
                }
                else if(!stk.empty() && is_open(s[stk.top()])){
                    stk.pop();
                    if(!stk.empty()){
                        result = max(result,i-stk.top());
                    }
                }
                else{
                    stk.push(i);
                }
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
        string S;
        cin >> S; 
        Solution ob;
        cout << ob.findMaxLen(S) << endl;
    }
    return 0;
}
  // } Driver Code Ends