// { Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++
class Solution {
    
    long long atmostK(vector<int> A,int n,long long k){
        
        long long i = 0,j = 0,sum = 0;
        long long count = 0;
        unordered_map<int,int> hash;
        
        while(j<n){
            
            sum+=A[j];
            
            if(sum<=k){
                count +=(j-i+1);
            }
            else{
                while(i<j && sum>k){
                    
                    sum-=A[i];
                    i++;
                    if(sum<=k)
                        count+=(j-i+1);
                }
            }
            j++;
        }
        return count;
    }
    
  public:
    long long countSubarray(int N,vector<int> A,long long L,long long R) {
        // code here
        if(N==1){
            return A[0]>=L && A[0]<=R?1:0;
        }
        
        return atmostK(A,N,R)-atmostK(A,N,L-1);
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        long long L,R;
        cin>>N>>L>>R;
        vector<int> A(N);
        for(int i=0;i<N;i++){
            cin>>A[i];
        }
        Solution obj;
        auto ans = obj.countSubarray(N,A,L,R);
        cout<<ans<<endl;
    }
}    // } Driver Code Ends