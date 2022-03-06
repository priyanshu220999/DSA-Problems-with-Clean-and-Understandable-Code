// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
/*You are required to complete this method*/

// arr[] : the input array containing 0s and 1s
// N : size of the input array

// return the maximum length of the subarray
// with equal 0s and 1s
class Solution{
    
    bool is_even(int num){
        return num%2==0;
    }
    
  public:
    int maxLen(int arr[], int N)
    {
        // Your code here
        
        if(N==1) return 0;
        if(N==2){
            return arr[0]==arr[1]?0:2;
        }
        
        unordered_map<int,int> hash;
        int sum = 0,result = 0;
        hash[0]=-1;
        for(int i=0;i<N;i++){
            
            if(arr[i]==0) sum-=1;
            else sum+=1;
            
            if(hash.find(sum)==hash.end()){
                hash[sum] = i;
            }
            else{
                if(is_even(i-hash[sum]) || sum==0){
                    result = max(result,i-hash[sum]);
                }
            }
        }
        return result;
    }
};


// { Driver Code Starts.

int main()
{
    // your code goes here
    int T;
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        Solution obj;
        cout << obj.maxLen(a, n) << endl;
    }
    return 0;
}  // } Driver Code Ends