// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution{
  public:
    int longestKSubstr(string s, int k) {
        
        int n = s.size();
        
        if(k>n){
            return -1;
        }
        if((n==1 && k==1)){
            return 1;
        }
        int result = -1;
        int i=0,j=0;
        unordered_map<char,int> hash;
        
        while(j<n){
            
            hash[s[j]]++;
            int h = hash.size();
            if(h==k){
                result = max(result,j-i+1);
            }
            else if(h>k){
                while(hash.size()>k){
                    
                    hash[s[i]]--;
                    
                    if(hash[s[i]]==0){
                        hash.erase(s[i]);
                    }
                    i++;
                }
            }
            j++;
        }
        return result;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int k;
        cin >> k;
        Solution ob;
        cout << ob.longestKSubstr(s, k) << endl;
    }
}
  // } Driver Code Ends