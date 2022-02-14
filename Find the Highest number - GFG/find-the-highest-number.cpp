// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution {
public:
    int findPeakElement(vector<int>& a) 
    {
        // Code here.
        
        int n = a.size();
        
        if(n==2){
            return a[0]>a[1]?a[0]:a[1];
        }
        
        if(a[n-1]>a[n-2]){
            return a[n-1];
        }
        
        if(a[0]>a[1]){
            return a[0];
        }
        
        int low = 0,high = n-1;
        
        while(low<=high){
            
            int mid = (low+high)/2;
            
            int cur_ele = a[mid];
            int next_ele = mid+1<n?a[mid+1]:-1;
            int prev_ele = mid-1>=0?a[mid-1]:-1;
            
            if(cur_ele>prev_ele && cur_ele>next_ele){
                return cur_ele;
            }
            else if(cur_ele<prev_ele){
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return -1;
    }
};



// { Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	int n;
    	cin >> n;
    	vector<int>a(n);
    	for(int i = 0; i < n; i++)
    		cin>>a[i];
    	Solution ob;
    	int ans = ob.findPeakElement(a);
    	cout << ans << "\n";
    }
	return 0;
}

  // } Driver Code Ends