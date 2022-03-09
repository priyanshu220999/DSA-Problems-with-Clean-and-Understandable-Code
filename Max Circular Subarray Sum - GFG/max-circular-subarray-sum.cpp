// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
    public:
    // arr: input array
    // num: size of array
    //Function to find maximum circular subarray sum.
    int circularSubarraySum(int arr[], int num){
        
        // your code here
        int sum =0;
        for(int i=0;i<num;i++){
            sum+=arr[i];
        }
        int cur_min = arr[0],min_so_far=arr[0],cur_max=arr[0],max_so_far = arr[0];
        
        for(int i=1;i<num;i++){
            
            cur_max=max(arr[i],cur_max+arr[i]);
            max_so_far = max(max_so_far,cur_max);
            
            cur_min=min(arr[i],cur_min+arr[i]);
            min_so_far = min(min_so_far,cur_min);
            
        }
        if(sum==min_so_far){
            return max_so_far;
            
        }
        return max(max_so_far,sum-min_so_far);
    }
};

// { Driver Code Starts.

int main()
 {
	int T;
	
	//testcases
	cin>> T;
	
	while (T--)
	{
	    int num;
	    
	    //size of array
	    cin>>num;
	    int arr[num];
	    
	    //inserting elements
	    for(int i = 0; i<num; i++)
	        cin>>arr[i];
	        
	    Solution ob;
	    //calling function
	    cout << ob.circularSubarraySum(arr, num) << endl;
	    
	}
	
	return 0;
}  // } Driver Code Ends