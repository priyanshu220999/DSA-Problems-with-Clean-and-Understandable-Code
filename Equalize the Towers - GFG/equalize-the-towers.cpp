// { Driver Code Starts
 
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
    
    void find_min_and_max(int h[],int n,int &low,int &high){
        
        int maxi = INT_MIN;
        int mini = INT_MAX;
        
        for(int i=0;i<n;i++){
            maxi = max(maxi,h[i]);
            mini = min(mini,h[i]);
        }
        low = mini;
        high = maxi;
    }
    
    long long int get_cost(int h[],int cost[],int n,int mid){
        
        long long int cur_cost = 0;
        
        for(int i=0;i<n;i++){
            
            cur_cost += (abs(mid-h[i])*cost[i]);
        }
        return cur_cost;
    }
    
	public:
	long long int Bsearch(int n, int h[], int cost[]) 
	{ 
		// Your code goes here
		
		if(n==1) return 0;
		
		int low,high;
		
		find_min_and_max(h,n,low,high);
		
		while(low<=high){
		    
		    int mid = (high-low)/2 + low;
		    
		    long long int m = get_cost(h,cost,n,mid);
		    
		    long long int next = get_cost(h,cost,n,mid+1);
		    
		    long long int prev = get_cost(h,cost,n,mid-1);
		    
		    if(m<=prev && m<=next){
		        return m;
		    }
		    else if(m>prev){
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

int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
    	 int n;
        cin>>n;
        
        int h[n], c[n];
        for(int i=0; i<n; i++)
            cin>>h[i];
        
        for(int i=0; i<n; i++)
            cin>>c[i];
            
        
        

        Solution ob;
		cout << ob.Bsearch(n,h,c);
        
	    cout << "\n";
	     
    }
    return 0;
}





  // } Driver Code Ends