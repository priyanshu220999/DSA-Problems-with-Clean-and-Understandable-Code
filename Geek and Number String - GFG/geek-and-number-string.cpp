// { Driver Code Starts
//Initial template for C++
 
#include<bits/stdc++.h>
using namespace std; 

 // } Driver Code Ends
//User function template for C++

class Solution{
    
    bool is_good(char a,char b){
        
        string test = "";
        test+=a;
        test+=b;
        
        if(test=="12" || test=="21" || test=="34" || test=="43"
        || test=="56" || test=="65" || test=="78" || test=="87"
        || test=="09" || test=="90")
        return true;
        return false;
    }
    
public:
    int minLength(string s, int n) {
        // code here
        
        if(n==1){
            return n;
        }
        int lim = 0;
        stack<char> stk;
        bool in_out = false;
        
        for(int i=0;i<n;i++){
            
            if(stk.empty()){
                stk.push(s[i]);
            }
            else{
                
                if(is_good(stk.top(),s[i])){
                    stk.pop();
                }
                else{
                    stk.push(s[i]);
                }
            }
        }
        return stk.size();
    }
};


// { Driver Code Starts.

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;

        string s;
        cin >> s;

        Solution obj;
        cout << obj.minLength(s, n) << "\n";
    }
    return 0;
}  // } Driver Code Ends