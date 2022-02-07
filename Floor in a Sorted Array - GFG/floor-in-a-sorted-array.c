// { Driver Code Starts
//Initial Template for C

#include <stdio.h>
#include <stdlib.h>


 // } Driver Code Ends
//User function Template for C

// Function to find floor of K
// arr[]: integer array of size N
// N: size of arr[]
// K: element whose floor is to find
int findFloor(long long int arr[], int N, long long int K) {
    
    //Your code here
    
    int left = 0;
    int right = N-1;
    
    int result = -1;
    
    if(arr[0]>K) return -1;
    if(arr[0]==K) return 0;
    
    while(left<=right){
        
        int mid = (left+right)/2;
        
        int cur_ele = arr[mid];
        
        if(cur_ele==K) return mid;
        else if(cur_ele<K){
            
            result = mid;
            left = mid+1;
        }
        else 
            right = mid-1;
    }
    return result;
}

// { Driver Code Starts.

int main() {
	
	long long int t;
	scanf("%lld", &t);
	
	while(t--){
	    int n;
	    scanf("%d", &n);
	    long long int x;
	    scanf("%lld", &x);
	    
	    long long int *arr;
		arr = (long long int *)malloc(n * sizeof(long long int));
	    
	    for(int i = 0;i<n;i++){
	        scanf("%lld", &arr[i]);
	    }
	    printf("%d\n", findFloor(arr, n, x) );
	   
	}
	
	return 0;
}

  // } Driver Code Ends