// { Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


 // } Driver Code Ends
class Solution{

    // Function to find the trapped water between the blocks.
    
    vector<int> get_left_greater(int arr[],int n){
        
        stack<int> stk;
        
        vector<int> result(n);
        
        for(int i = 0;i<n;i++){
            
            while(!stk.empty() && stk.top()<=arr[i]){
                stk.pop();
            }
            result[i] = stk.empty()?arr[i]:stk.top();
            if(stk.empty() || stk.top()<arr[i]) stk.push(arr[i]);
            // cout<<result[i]<<" ";
        }
        // cout<<endl;
        return result;
    }
    
    vector<int> get_right_greater(int arr[],int n){
        
        stack<int> stk;
        
        vector<int> result(n);
        
        for(int i = n-1;i>=0;i--){
            
            while(!stk.empty() && stk.top()<=arr[i]){
                stk.pop();
            }
            result[i] = stk.empty()?arr[i]:stk.top();
            if(stk.empty() || stk.top()<arr[i]) stk.push(arr[i]);
            // cout<<result[i]<<" ";
        }
        // cout<<endl;
        return result;
    }
    
    public:
    long long trappingWater(int arr[], int n){
        // code here
        
        vector<int> left_greater = get_left_greater(arr,n);
        vector<int> right_greater = get_right_greater(arr,n);
        
        long long result = 0;
        
        for(int i = 0;i<n;i++){
            
            result +=(min(left_greater[i],right_greater[i])-arr[i]);
        }
        return result;
    }
};

// { Driver Code Starts.

int main(){
    
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        
        int a[n];
        
        //adding elements to the array
        for(int i =0;i<n;i++){
            cin >> a[i];            
        }
        Solution obj;
        //calling trappingWater() function
        cout << obj.trappingWater(a, n) << endl;
        
    }
    
    return 0;
}  // } Driver Code Ends