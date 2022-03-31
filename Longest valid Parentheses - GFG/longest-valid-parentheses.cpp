// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
    
    bool is_open(char c){
        return c=='(';
    }
    bool is_close(char c){
        return c==')';
    }
    
public:
    int maxLength(string S){
        // code here
        
        int n = S.size();
        
        if(n==1){
            return 0;
        }
        
        stack<int> stk;
        int result = 0;
        stk.push(-1);
        
        for(int i=0;i<n;i++){
            
            if(is_open(S[i])){
                stk.push(i);
            }
            else{
                if(!stk.empty() && is_open(S[stk.top()])){
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

int main(){
    int t;
    cin>>t;
    while(t--){
        string S;
        cin>>S;
        
        Solution ob;
        cout<<ob.maxLength(S)<<"\n";
    }
    return 0;
}  // } Driver Code Ends