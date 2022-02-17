// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    vector<int> primeRange(int M, int N) {
        // code here
        
        vector<bool> primes(N+1,true);
        
        primes[1] = false;
        
        vector<int> result;
        
        for(int i=2;i*i<=N;i++){
            if(primes[i]){
                
                for(long int j = i*i;j<=N;j+=i){
                    primes[j] = false;
                }
                
            }
        }
        
        for(int i=M;i<=N;i++){
            if(primes[i]){
                result.push_back(i);
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
        int N, M, K;
        cin >> M >> N;
        Solution ob;
        vector<int> ans = ob.primeRange(M, N);
        for (auto u : ans) cout << u << " ";
        cout << "\n";
    }
}  // } Driver Code Ends