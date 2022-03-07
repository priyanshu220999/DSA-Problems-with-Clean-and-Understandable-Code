// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int countOfSubstrings(string S, int K) {
        // code here
        
        int n = S.size();
        
        if(K==1 || n==1){
            return 0;
        }
        
        unordered_map<int,int> hash;
        int i = 0,j = 0,result = 0;
        
        while(j<n){
            
            hash[S[j]]++;
            
            if(j>=K-1){
                
                if(hash.size()==K-1)
                    result++;
                hash[S[i]]--;
                if(hash[S[i]]==0)
                    hash.erase(S[i]);
                i++;
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
        string S;
        int K;
        cin>>S;
        cin>>K;

        Solution ob;
        cout << ob.countOfSubstrings(S,K) << endl;
    }
    return 0;
}  // } Driver Code Ends