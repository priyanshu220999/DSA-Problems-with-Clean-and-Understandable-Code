// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution{   
    
    int max_num(vector<int> arr){
        
        int result = INT_MIN;
        
        for(int i:arr){
            result = max(i,result);
        }
        return result;
    }
    
    int sum(vector<int> arr){
        
        int result = 0;
        
        for(int i:arr){
            result+=i;
        }
        return result;
    }
    
public:
    int maximumSumSubarray(int K, vector<int> &Arr , int N){
        // code here 
        
        if(K==1){
            return max_num(Arr);
        }
        if(K==N){
            return sum(Arr);
        }
        int cur_sum = 0;
        int max_sum = INT_MIN;
        int i = 0,j = 0;
        
        for(;j<K;j++){
            cur_sum+=Arr[j];
        }
        j--;
        
        for(;j<N;j++,i++){
            
            if(i==0){
                max_sum = max(max_sum,cur_sum);
            }
            else{
                cur_sum+=Arr[j];
                max_sum = max(cur_sum,max_sum);
            }
            cur_sum-=Arr[i];
        }
        return max_sum;
    }
};

// { Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N,K;
        cin >> N >> K;;
        vector<int>Arr;
        for(int i=0;i<N;++i){
            int x;
            cin>>x;
            Arr.push_back(x);
        }
        Solution ob;
        cout << ob.maximumSumSubarray(K,Arr,N) << endl;
    }
    return 0; 
}   // } Driver Code Ends