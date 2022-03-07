// { Driver Code Starts
// C++ program to find largest subarray sum with
// at-least k elements in it.
#include <bits/stdc++.h>
using namespace std;

long long int maxSumWithK(long long int a[], long long int n, long long int k);

// Driver code
int main() {
    long long int t;
    cin >> t;
    while (t--) {
        long long int n, k, i;
        cin >> n;
        long long int a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        cin >> k;
        cout << maxSumWithK(a, n, k) << endl;
    }
    return 0;
}
// } Driver Code Ends


long long int maxSumWithK(long long int a[], long long int n, long long int k) 
{
    if(n==1){
        return a[0];
    }
    
    vector<long long int> max_sum(n);
    max_sum[0] = a[0];
    long long int cur_sum = a[0];
    long long int sum = 0;
    
    for(long long int i = 1;i<n;i++){
        cur_sum = max(a[i],cur_sum+a[i]);
        max_sum[i] = cur_sum;
    }
    
    for(long long int i = 0;i<k;i++)
        sum+=a[i];
    
    long long int result = sum;
    
    for(long long int i = k;i<n;i++){
        
        sum+=(a[i]-a[i-k]);
        
        result = max(result,sum);
        
        result = max(result,sum+max_sum[i-k]);
    }
    return result;
}