// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
  public:
    string reverseWords (string s)
    {
        //code here.
        
        int n = s.size();
        
        if(n==1){
            return s;
        }
        stack<char> stk;
        string result = "";
        vector<string> collection;
        string temp = "";
        
        
        for(int i=0;i<n;i++){
            stk.push(s[i]);
        }
        while(!stk.empty()){
            
            if(stk.top()=='.'){
                collection.push_back(temp);
                temp = "";
            }
            else{
                temp+=stk.top();
            }
            stk.pop();
        }
        
        collection.push_back(temp);
        
        int cn = collection.size();
        for(int i=cn-1;i>=0;i--){
            
            result +=collection[i];
            if(i>0)
                result+='.';
        }
        return result;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s; cin >> s;
        Solution ob;
        cout << ob.reverseWords (s) << endl;
    }
    return 0;
}

// Contributed By: Pranay Bansal
  // } Driver Code Ends