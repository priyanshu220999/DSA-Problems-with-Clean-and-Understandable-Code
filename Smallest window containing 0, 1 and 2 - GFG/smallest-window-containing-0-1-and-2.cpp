// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int smallestSubstring(string S) {
        // Code here
        
        int n = S.size();
        
        if(n<3) return -1;
        
        unordered_map<int,int> hash;
        
        int result = n+1,i = 0,j = 0;
        
        while(j<n){
            
            hash[S[j]]++;
            
            if(hash.size()==3){
                
                if(j-i+1==3) return 3;
                
                result = min(result,j-i+1);
                
                while(hash.size()==3){
                    
                    hash[S[i]]--;
                    if(hash[S[i]]==0) hash.erase(S[i]);
                    i++;
                    if(hash.size()==3)
                        result = min(result,j-i+1);
                }
            }
            j++;
        }
        
        if(result==n+1)
            return -1;
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
        cout << ob.smallestSubstring(S);
        cout << endl;
    }
}  // } Driver Code Ends