// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
    
    bool is_pair_available(int A[],int n,int target,int begin){
    
        unordered_map<int,int> hash;
        
        for(int i = begin;i<n;i++){
            
            if(hash.find(target-A[i])!=hash.end()){
                return true;
            }
            hash[A[i]] = 1;
        }
        return false;
    }
    
    public:
    //Function to find if there exists a triplet in the 
    //array A[] which sums up to X.
    bool find3Numbers(int A[], int n, int X)
    {
        //Your Code Here
        if(n<3) return false;
        if(n==3) return A[0]+A[1]+A[2]==X;
        
        for(int i=0;i<n;i++){
            
            if(is_pair_available(A,n,X-A[i],i+1))
                return true;
        }
        return false;
    }

};

// { Driver Code Starts.

int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		int n,X;
		cin>>n>>X;
		int i,A[n];
		for(i=0;i<n;i++)
			cin>>A[i];
		Solution ob;
        cout <<  ob.find3Numbers(A, n, X) << endl;
    }
}
  // } Driver Code Ends