class Solution {
public:
    int minimumSize(vector<int>& nums, int maxOperations) {
        
        int n = nums.size();
        
        if(n==1 && nums[0]==1){
            return nums[0];
        }
        
        // if(maxOperations==1){
        //     int max_index = get_max_index(nums,n);
        //     if(is_even(nums[max_index]))
        //         nums[max_index]/=2;
        //     else
        //         nums[max_index]/=2;
        // }
        
        int low = 1,high = 1e9;
        
        while(low<high){
            
            int mid = low + (high-low)/2,cur_ops = 0;
            
            for(int i:nums)
                cur_ops+=(i-1)/mid;
            
            if(cur_ops<=maxOperations)
                high = mid;
            else 
                low = mid+1;
            
        }
        return low;
    }
};