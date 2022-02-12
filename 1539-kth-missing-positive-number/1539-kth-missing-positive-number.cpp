class Solution {
public:
    
//     int findKthPositive(vector<int>& arr, int k) {
//         int n = arr.size();
        
//         if(arr[0]>k) return k;
        
//         if(arr[n-1] == n) return n+k;
        
//         int low = 0,high = n;
        
//         while(low<high){
            
//             int mid = (low+high)/2;
            
//             if(arr[mid]-1-mid<k){
//                 low = mid+1;
//             }
//             else
//                 high = mid;
            
//         }
//         return low+k;

//     }
    
    int findKthPositive(vector<int>& arr, int k) {
        
        for(int i:arr){
            if(i<=k)
                k++;
            else
                break;
        }
        return k;
    }
};