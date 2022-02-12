class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        
        int n = nums.size();
        
        if(n==1){
            if(nums[0]==target) return 0;
            return nums[0]>target?0:1;
        }
        
        if(nums[n-1]==target) return n-1;
        if(nums[0]>=target) return 0;
        if(nums[n-1]<target) return n;
        
        int low = 0,high = n-1;
        
        while(low<=high){
            
            int mid = (low+high)/2;
            
            int cur_ele = nums[mid];
            
            if(cur_ele==target)
                return mid;
            else if(cur_ele<target)
                low = mid+1;
            else
                high = mid-1;
        }
        return low;
    }
};