class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        
        int n = nums.size();
        
        if(n==1)
            return 0;
        
        if(n==2){
            return nums[0]>nums[1]?0:1;
        }
        
        int left = 0,right = n-1;
        
        while(left<=right){
            
            int mid = (left+right)/2;
            
            int cur_ele = nums[mid];
            
            
            if(mid>0 && mid<n-1){
                
                int next_ele = nums[mid+1];
                int prev_ele = nums[mid-1];
                
                if(cur_ele>prev_ele && cur_ele>next_ele)
                    return mid;
                else if(cur_ele>prev_ele)
                    left = mid+1;
                else
                    right = mid-1;
            }
            else if(mid==0){
                int next_ele = nums[mid+1];
                return next_ele<cur_ele?0:1;
            }
            else{
                int prev_ele = nums[mid-1];
                return cur_ele>prev_ele?n-1:n-2;
            }
        }
        return -1;
    }
};