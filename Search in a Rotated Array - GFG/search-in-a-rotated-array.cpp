// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
    
    bool is_sorted(int left,int right){
        return left<=right;
    }
    
    int bin_search(int a[],int left,int right,int key){
        
        int result = -1;
        
        while(left<=right){
            
            int mid = (left+right)/2;
            
            int cur_element = a[mid];
            
            if(cur_element == key)
                return mid;
            else if(cur_element < key)
                left = mid+1;
            else
                right = mid-1;
            
        }
        return result;
    }
    
    int find_min_index(int a[],int l,int h){
        
        
        
        int n = (h-l+1);
        while(l<=h){
            
            if(is_sorted(a[l],a[h]))
                return l;
            
            int mid = (l+h)/2;
            
            int next = (mid+1)%n;
            
            int prev = (mid-1+n)%n;
            
            if(a[next]>=a[mid] && a[prev]>=a[mid])
                return mid;
            else if(is_sorted(a[l],a[mid]))
                l = mid+1;
            else
                h = mid-1;
            
        }
        return l;
    }
    
    public:
    int search(int a[], int l, int h, int key){
    //complete the function here
    
        if(is_sorted(a[l],a[h])) return bin_search(a,l,h,key);
        
        int min_index = find_min_index(a,l,h);
        
        if(a[min_index]==key) return min_index;
        
        int result = bin_search(a,l,min_index-1,key);
        
        if(result!=-1) return result;
        
        result = bin_search(a,min_index+1,h,key);
        
        return result;
    }
};

// { Driver Code Starts. 
int main() {
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int A[n];
        for(int i = 0; i < n; i++)
            cin >> A[i];
        int key;
        cin >> key;
        Solution ob;
        cout << ob.search(A, 0, n - 1, key) << endl;
    }
return 0;
}  // } Driver Code Ends