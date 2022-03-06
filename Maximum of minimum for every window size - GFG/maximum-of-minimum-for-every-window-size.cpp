// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends

class Solution
{
    vector<int> next_smaller(int arr[],int n){
        
        stack<int> stk;
        vector<int> result(n,n);
        
        for(int i = n-1;i>=0;i--){
            
            while(!stk.empty() && arr[stk.top()]>=arr[i]){
                stk.pop();
            }
            if(stk.empty()) result[i] = n;
            else result[i] = stk.top();
            stk.push(i);
        }
        
        return result;
    }
    
    vector<int> previous_smaller(int arr[],int n){
        
        stack<int> stk;
        vector<int> result(n,-1);
        
        for(int i = 0;i<n;i++){
            
            while(!stk.empty() && arr[stk.top()]>=arr[i]){
                stk.pop();
            }
            
            if(!stk.empty())
                result[i] = stk.top();
                
            stk.push(i);
        }
        
        return result;
    }
    
    public:
    //Function to find maximum of minimums of every window size.
    vector <int> maxOfMin(int arr[], int n)
    {
        // Your code here
        vector<int> next = next_smaller(arr,n);
        vector<int> prev = previous_smaller(arr,n);
        
        vector<int> result(n,0);
        
        for(int i=0;i<n;i++){
            
            int window = (next[i]-prev[i]-1);
            
            result[window-1] = max(result[window-1],arr[i]);
        }
        
        for(int i = n-2;i>=0;i--){
            result[i] = max(result[i],result[i+1]);
        }
        return result;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) cin >> a[i];
        Solution ob;
        vector <int> res = ob.maxOfMin(a, n);
        for (int i : res) cout << i << " ";
        cout << endl;
    }
    return 0;
}
  // } Driver Code Ends