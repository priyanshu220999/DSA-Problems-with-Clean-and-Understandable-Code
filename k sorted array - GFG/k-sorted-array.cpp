// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution {
    
    int bin_search(vector<int> arr,int n,int target){
        
        int low = 0,high = n-1;
        
        if(arr[low]==target) return low;
        
        if(arr[high]==target) return high;
        
        while(low<=high){
            
            int mid = (low+high)/2;
            
            int cur_ele = arr[mid];
            
            if(cur_ele==target) return mid;
            
            else if(cur_ele<target) low = mid+1;
            
            else high = mid-1;
            
        }
        return 0;
    }
    
  public:
    string isKSortedArray(int arr[], int n, int k)
    {
        //code here.
        vector<pair<int,int>> hash;
        
        for(int i=0;i<n;i++){
            hash.push_back(make_pair(arr[i],i));
        }
        
        sort(hash.begin(),hash.end());
        
        for(int i=0;i<n;i++){
            
            if(abs(i-hash[i].second)>k)
                return "No";
        }
        return "Yes";
    }
};

// { Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n,k;
	    cin>>n;
	    int arr[n];
	    for(int i=0;i<n;i++)
	    cin>>arr[i];
	    cin>>k;
	    Solution ob;
	cout <<ob.isKSortedArray(arr, n, k)<<endl;
	}
	return 0;	 
}  // } Driver Code Ends