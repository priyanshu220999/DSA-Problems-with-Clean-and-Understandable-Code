class Solution {
    
    bool is_sorted(vector<int> nums,int left,int right){
        return nums[left]<=nums[right];
    }
    
    int find_min_index(vector<int> nums,int n,int target){
        
        int result = -1;
        
        int left = 0,right = n-1;
        
        while(left<=right){
            
            if(is_sorted(nums,left,right))
                return left;
            
            int mid = (left+right)/2;
            
            int next = (mid+1)%n;
            
            int prev = (mid-1+n)%n;
            
            if(nums[next]>=nums[mid] && nums[prev]>=nums[mid])
                return mid;
            else if(is_sorted(nums,left,mid))
                left = mid+1;
            else 
                right = mid-1;
        }
        return -1;
    }
    
    int bin_search(vector<int> nums,int left,int right,int target){
        
        while(left<=right){
            
            int mid = (left+right)/2;
            
            if(nums[mid]==target)
                return mid;
            else if(nums[mid]<target)
                left = mid+1;
            else
                right = mid-1;
        }
        return -1;
    }
    
public:
    int search(vector<int>& nums, int target) {
        
        int n = nums.size();
        
        if(n==1){
            if(nums[0]==target)
                return 0;
            return -1;
        }
        
        int left = 0,right = n-1;
        
        if(is_sorted(nums,left,right))
            return bin_search(nums,left,right,target);
        
        int min_index = find_min_index(nums,n,target);
        
        if(nums[min_index]==target)
            return min_index;
        
        if(min_index==n-1)
            return bin_search(nums,left,right-1,target);
        
        if(target<=nums[min_index-1] && target>=nums[left])
            return bin_search(nums,left,min_index-1,target);
        
        return bin_search(nums,min_index+1,right,target);
        
    }
};