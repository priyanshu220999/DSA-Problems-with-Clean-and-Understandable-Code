// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    int searchInsertK(vector<int>Arr, int N, int k)
    {
        // code here
        
        if(Arr[0]>=k) return 0;
        if(Arr[N-1]==k) return N-1;
        if(Arr[N-1]<k) return N;
        
        int low = 0,high = N-1;
        
        while(low<=high){
            
            int mid = (low+high)/2;
            
            int cur_ele = Arr[mid];
            
            if(cur_ele==k)
                return mid;
            else if(cur_ele<k)
                low = mid+1;
            else
                high = mid-1;
        }
        return low;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin >> N;
        vector<int>Arr(N);
        for(int i=0;i<N;i++)    
            cin>>Arr[i];
        int k;
        cin>>k;
        Solution obj;
        cout<<obj.searchInsertK(Arr, N, k)<<endl;
    }
    return 0;
}  // } Driver Code Ends