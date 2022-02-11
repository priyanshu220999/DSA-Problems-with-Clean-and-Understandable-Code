// { Driver Code Starts
// Initial template for C++

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template in C++

class Solution 
{
    
    void find_max_and_sum(int A[],int n,int &sum,int &maxi){
        
        for(int i = 0;i<n;i++){
            sum+=A[i];
            if(A[i]>maxi){
                maxi = A[i];
            }
        }
        return;
    }
    
    bool is_valid(int limit,int A[],int n,int m){
        
        int pages = 0;
        int students = 1;
        int i = 0;
        
        while(i<n){
            
            if(A[i]>limit) 
                return false;
            else if(pages+A[i]>limit){
                students++;
                pages = A[i];
                if(students>m) 
                    return false;
            }
            else{
                pages += A[i];
            }
            i++;
        }
        return true;
    }
    
    public:
    //Function to find minimum number of pages.
    int findPages(int A[], int N, int M) 
    {
        //code here
        
        if(N<M) return -1;
        
        int result = -1;
        
        int maxi = INT_MIN,sum = 0;
        
        find_max_and_sum(A,N,sum,maxi);
        
        if(N==M) return maxi;
        
        int low = 0,high = sum;
        
        while(low<=high){
            
            int mid = (low+high)/2;
            
            if(is_valid(mid,A,N,M)){
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

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int A[n];
        for(int i=0;i<n;i++){
            cin>>A[i];
        }
        int m;
        cin>>m;
        Solution ob;
        cout << ob.findPages(A, n, m) << endl;
    }
    return 0;
}
  // } Driver Code Ends