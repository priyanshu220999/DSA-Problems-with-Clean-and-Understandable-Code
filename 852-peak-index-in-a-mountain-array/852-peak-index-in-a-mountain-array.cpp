class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        
        int n = arr.size();
        
        if(n==3)
            return 1;
        
        int low = 0,high = n-1;
        
        while(low<=high){
            
            int mid = (low+high)/2;
            int cur_ele = arr[mid];
            int next_ele = mid+1<n?arr[mid+1]:-1;
            int prev_ele = mid-1>=0?arr[mid-1]:-1;
            
            if(cur_ele>next_ele && cur_ele>prev_ele)
                return mid;
            else if(cur_ele<next_ele)
                low = mid+1;
            else
                high = mid-1;
            
        }
        return -1;
    }
};