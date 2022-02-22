// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    int findSubArraySum(int Arr[], int N, int k)
    {
        // code here
        if(N==1){
            return Arr[0]==k?1:0;
        }
        int count = 0;
        unordered_map<int,int> hash;
        int sum = 0;
        hash[sum]++;
        for(int i=0;i<N;i++){
            
            sum+=Arr[i];
            
            if(hash.find(sum-k)!=hash.end()){
                count += hash[sum-k];
            }
            hash[sum]++;
        }
        return count;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin >> N;
        int Arr[N];
        for(int i=0;i<N;i++)    
            cin>>Arr[i];
        int k;
        cin>>k;
        Solution obj;
        cout<<obj.findSubArraySum(Arr, N, k)<<endl;
    }
    return 0;
}  // } Driver Code Ends