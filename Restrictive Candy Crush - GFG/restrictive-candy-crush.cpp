// { Driver Code Starts
#include <iostream>
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
    public:
    string Reduced_String(int k,string s){
        // Your code goes here
        
        int n = s.size();
        
        if(k==1){
            return "";
        }
        if(n==1){
            return s;
        }
        
        stack<pair<char,int>> stk;
        string result = "";
        
        for(int i=0;i<n;i++){
            
            if(stk.empty()){
                stk.push({s[i],1});
            }
            else if(stk.top().first==s[i]){
                
                stk.push({s[i],stk.top().second+1});
                
                if(stk.top().second==k){
                    
                    int j = k;
                    
                    while(j){
                        stk.pop();
                        j--;
                    }
                }
            }
            else{
                stk.push({s[i],1});
            }
        }
        while(!stk.empty()){
            result +=stk.top().first;
            stk.pop();
        }
        reverse(result.begin(),result.end());
        return result;
    }


};

// { Driver Code Starts.

int main() {
    
    
    int t;cin>>t;
    while(t--)
    {
        int k;
        cin>>k;
        string s;
        cin>>s;
        Solution obj;
        cout<<obj.Reduced_String(k,s)<<"\n";
        
    }
    
	return 0;
}  // } Driver Code Ends