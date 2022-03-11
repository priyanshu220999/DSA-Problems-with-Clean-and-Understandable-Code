// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

int save_gotham(int arr[], int n);



int main() {
    
    int t;
    cin>> t;
    while(t--)
    {
        int n;cin>>n;
        int arr[n];
        
        for(int i=0;i<n;i++)
            cin>>arr[i];
        
        cout << save_gotham(arr, n) << endl;
    }
    
	return 0;
}// } Driver Code Ends


int save_gotham(int arr[], int n)
{
    // Complete the function
    
    if(n==1) return 0;
    
    int mod = 1000000001;
    
    stack<int> stk;
    
    int result = 0;
    
    for(int i = n-1;i>=0;i--){
        
        while(!stk.empty() && stk.top()<=arr[i]){
            stk.pop();
        }
        if(!stk.empty()){
            result+=stk.top();
        }
        stk.push(arr[i]);
    }
    
    return result%mod;
}