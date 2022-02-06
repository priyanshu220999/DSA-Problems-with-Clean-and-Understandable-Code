class Solution {
    
    bool is_unsorted(vector<int> nums,int left,int right){
        return nums[left]>nums[right];
    }
    
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        
        int left = 0,right = n-1;
        
        while(left<=right){
            
            int mid = (left+right)/2;
            
            if(is_unsorted(nums,mid,right))
                left = mid+1;
            else if(is_unsorted(nums,left,mid)){
                right = mid;
                left++;
            }
            else{
                right--;
            }
            
        }
        return nums[left];
    }
};