class Solution {
    
    public:
    bool isLeftSorted(vector<int> nums,int l,int mid){
        return nums[l]<=nums[mid];
    }
    
    bool isRightSorted(vector<int> nums,int mid,int r){
        return nums[mid]<=nums[r];
    }
    int search(vector<int>& nums, int target) {
        
        int l = 0,h = nums.size()-1;
        
        while(l<=h){
            int mid = (l+h)/2;
            if(nums[mid]==target){
                return mid;
            }
            else if(isLeftSorted(nums,l,mid)){
                if(target<nums[mid] && target>=nums[l]){
                    if(target==nums[l]){
                        return l;
                    }
                    else{
                        h=mid-1;
                    }
                }
                else{
                    l = mid+1;
                }
            }
            else {
                if(target>nums[mid] && target<=nums[h]){
                    if(target==nums[h]){
                        return h;
                    }
                    else{
                        l = mid+1;
                    }
                }
                else{
                    h = mid-1;
                }
            }
        }
        return -1;
    }
};