// { Driver Code Starts
// C++ implementation of For each element in 1st 
// array count elements less than or equal to it
// in 2nd array
#include <bits/stdc++.h>
 
using namespace std;


 // } Driver Code Ends
// function to count for each element in 1st array,
// elements less than or equal to it in 2nd array
class Solution{
    
    int bin_search(int arr[],int n,int target){
        
        if(arr[n-1]<=target){
            return n;
        }
        if(arr[0]>target){
            return 0;
        }
        
        int result = n;
        
        int l = 0,h = n-1;
        
        while(l<=h){
            int m = (l+h)/2;
            
            int cur_ele = arr[m];
            
            if(cur_ele<=target){
                result = m+1;
                l = m+1;
            }
            
            else h = m-1;
        }
        return result;
    }
    
  public:
    vector<int> countEleLessThanOrEqual(int arr1[], int arr2[], 
                                 int m, int n)
    {
        //Your code goes here
        
        vector<int> result;
        
        sort(arr2,arr2+n);
        
        for(int i=0;i<m;i++){
            
            int cur_ele = arr1[i];
            
            int less_or_equal_count = bin_search(arr2,n,cur_ele);
            
            result.push_back(less_or_equal_count);
        }
        return result;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int m,n;
        cin>>m>>n;
        int arr1[m],arr2[n];
        for(int i=0;i<m;i++)
        cin>>arr1[i];
        for(int j=0;j<n;j++)
        cin>>arr2[j];
        Solution obj;
        vector <int> res = obj.countEleLessThanOrEqual(arr1, arr2, m, n);
        for (int i = 0; i < res.size (); i++) cout << res[i] << " ";
        
        cout<<endl;
    }
    return 0;
}  // } Driver Code Ends