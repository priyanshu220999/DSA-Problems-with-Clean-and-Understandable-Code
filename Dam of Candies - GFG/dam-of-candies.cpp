// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution{
    
    public:
    int maxCandy(int height[], int n) 
    { 
        // Your code goes here
        
        if(n<=2){
            return 0;
        }
        
        int i = 0,j = n-1;
        
        int result = 0;
        
        while(i<j){
            
            int wall_height = min(height[i],height[j]);
            int area = wall_height*(j-i-1);
            
            if(area>result){
                result = area;
            }
            
            if(height[i]<height[j]){
                i++;
            }
            else{
                j--;
            }
        }
        return result;
    }   
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--)
    {
    	int n;
    	cin>>n;
    	int height[n];
    	for (int i = 0; i < n; ++i)
    	{
    		cin>>height[i];
    	}
    	
    	Solution obj;
    	
    	cout << obj.maxCandy(height,n)<<"\n";
    }
    return 0;
}  // } Driver Code Ends