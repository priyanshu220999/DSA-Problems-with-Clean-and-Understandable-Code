class Solution {
    
    int first_occurence(vector<int> nums,int n,int target){
        
        int result = -1;
        
        int low = 0,high = n-1;
        
        while(low<=high){
            
            int mid = (low+high)/2;
            
            int cur_element = nums[mid];
            
            if(cur_element == target){
                result = mid;
                high = mid-1;
            }
            else if(cur_element<target)
                low = mid+1;
            else
                high = mid-1;
        }
        return result;
    }
    
    int last_occurence(vector<int> nums,int n,int target){
        
        int result = -1;
        
        int low = 0,high = n-1;
        
        while(low<=high){
            
            int mid = (low+high)/2;
            
            int cur_element = nums[mid];
            
            if(cur_element == target){
                result = mid;
                low = mid+1;
            }
            else if(cur_element<target)
                low = mid+1;
            else
                high = mid-1;
        }
        return result;
    }
    
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        
        vector<int> result(2,-1);
        
        int n = nums.size();
        
        if(n==0)
            return result;
        if(n==1 && nums[0]==target)
            return {0,0};
        
        result[0] = first_occurence(nums,n,target);
        result[1] = last_occurence(nums,n,target);
        
        return result;
        
    }
};