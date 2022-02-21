// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

vector<long long> printFirstNegativeInteger(long long int arr[],
                                             long long int n, long long int k);

// Driver program to test above functions
int main() {
    long long int t, i;
    cin >> t;
    while (t--) {
        long long int n;
        cin >> n;
        long long int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        long long int k;
        cin >> k;

        vector<long long> ans = printFirstNegativeInteger(arr, n, k);
        for (auto it : ans) cout << it << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends

vector<long long> get_negatives_or_zero(long long int A[],long long int n){
    
    vector<long long> result;
    
    for(long long int i=0;i<n;i++){
        
        long long int temp = min(1ll*0,A[i]);
        result.push_back(temp);
    }
    return result;
}

long long int first_negative_or_zero(long long int A[],long long int n){
    
    long long int result;
    
    for(long long int i = 0;i<n;i++){
        if(A[i]<0){
            return A[i];
        }
    }
    return 0;
}

vector<long long> printFirstNegativeInteger(long long int A[],long long int N, long long int K) {
    
    vector<long long> result;
    
    if(N==1){  // Edge Case 1
        if(A[0]<0){
            result.push_back(A[0]);
        }
        else{
            result.push_back(0);
        }
        return result;
    }
    
    if(K==1){ // Edge Case 2 
        return get_negatives_or_zero(A,N);
    }
    
    if(K==N){ // Edge Case 3
        return {first_negative_or_zero(A,N)};
    }
    
    long long int i = 0,j = 0;
    vector<long long> negative;
    
    for(;j<K;j++){  // First Window 
        if(A[j]<0) negative.push_back(A[j]);
    }
    if(negative.empty()) result.push_back(0);
    else result.push_back(negative[0]);
    
    while(i<N && j<N){ // Further windows 
        
        if(A[i]<0){
            negative.erase(negative.begin());
        }
        i++;
        if(A[j]<0){
            negative.push_back(A[j]);
        }
        if(negative.empty()){
            result.push_back(0);
        }
        else{
            result.push_back(negative[0]);
        }
        j++;
    }
    return result; // Final Result 
 }