class Solution {
    
    bool is_sorted(vector<int> nums,int left,int right){
        return nums[left]<=nums[right];
    }
    
public:
    int findMin(vector<int>& nums) {
        
        int n = nums.size();
        
        int left = 0,right = n-1;
        
        
        
        while(left<=right){
            
            if(nums[left]<=nums[right])
                return nums[left];
            
            int mid = (left+right)/2;
            
            int next = (mid+1)%n;
            int prev = (mid-1+n)%n;
            
            if(nums[next]>=nums[mid] && nums[prev]>=nums[mid])
                return nums[mid];
            else if(is_sorted(nums,left,mid))
                left = mid+1;
            else if(is_sorted(nums,mid,right))
                right = mid-1;
            
        }
        return nums[0];
    }
};