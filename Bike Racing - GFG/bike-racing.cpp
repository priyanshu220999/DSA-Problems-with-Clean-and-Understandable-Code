// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
    
    long int get_total_fast_speed(long A[],long H[],long N,long L,long int mid){
        
        long int result = 0;
        
        for(long i=0;i<N;i++){
            
            long int ith_speed = H[i] + mid*A[i];
            
            if(ith_speed>=L){
                result += ith_speed;
            }
        }
        return result;
    }
    
public:
    long buzzTime(long N, long M, long L, long H[], long A[])
    {
        // code here
        
        long int low = 1,high = L>M?L:M;
        
        long int result = 1;
        
        while(low<=high){
            
            long int mid = (high-low)/2 + low;
            
            long int total_fast_speed = get_total_fast_speed(A,H,N,L,mid);
            
            if(total_fast_speed>=M){
                result = mid;
                high = mid-1;
            }
            else{
                low = mid+1;
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
        long N, M, L;
        cin>>N>>M>>L;
        long H[N], A[N];
        for(long i = 0;i < N;i++) 
            cin>>H[i]>>A[i];
        
        Solution ob;
        cout<<ob.buzzTime(N, M, L, H, A)<<"\n";
    }
    return 0;
}  // } Driver Code Ends