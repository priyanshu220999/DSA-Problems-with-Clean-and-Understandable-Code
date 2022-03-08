// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution{
    
    int atmostK(int a[],int n,int k){
        
        if(k==-1){
            return 0;
        }
        
        int i = 0,j = 0,count = 0;
        
        for(int j = 0;j<n;j++){
            
            if(a[j]<=k){
                count+=(j-i+1);
            }
            else{
                i = j+1;
            }
        }
        return count;
    }
    
    public:
    long countSubarrays(int a[], int n, int L, int R)
    {
        // Complete the function
        return atmostK(a,n,R)-atmostK(a,n,L-1);
    }
};

// { Driver Code Starts.
// driver program
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        
        int n ,l,r;
        cin >> n>>l>>r;
        int a[n];
        for(int i=0;i<n;i++)
        cin >> a[i];
        Solution ob;
    	cout << ob.countSubarrays(a, n, l, r)<<endl;
    }
	return 0;
}
  // } Driver Code Ends