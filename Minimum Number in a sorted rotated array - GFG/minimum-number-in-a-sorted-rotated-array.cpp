// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


class Solution
{
    bool is_sorted(int low,int high){
        return low<high;
    }
    
    public:
    //Function to find the minimum element in sorted and rotated array.
    int minNumber(int arr[], int low, int high)
    {
        // Your code here
        int n = (high-low+1);
        
        if(arr[high]<arr[high-1]) return arr[high];
        
        if(is_sorted(arr[low],arr[high])) return arr[0];
        
        if(high==0) return arr[0];
        
        if(high==1){
            return arr[0]>arr[1]?arr[0]:arr[1];
        }
        
        while(low<=high){
            
            int mid = low + (high-low)/2;
            
            int cur_ele = arr[mid];
            int next_ele = mid+1<n?arr[mid+1]:-1;
            int prev_ele = mid-1>=0?arr[mid-1]:-1;
            
            if(cur_ele<prev_ele && cur_ele<next_ele){
                return cur_ele;
            }
            else if(is_sorted(cur_ele,arr[n-1])){
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return 0;
    }
};

// { Driver Code Starts.


int main()
{
	
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int a[n];
		for(int i=0;i<n;++i)
			cin>>a[i];	
		Solution obj;
		cout << obj.minNumber(a,0,n-1) << endl;
	}
	return 0;
}  // } Driver Code Ends