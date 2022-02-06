class Solution {
    
    bool is_even(int n){
        return n%2==0;
    }
        
    bool is_odd(int n){
        return n%2==1;
    }
    
public:
    int singleNonDuplicate(vector<int>& nums) {
        
        int n = nums.size();
        
        if(n==1)
            return nums[0];
        
        int low = 0,high = n-1;
        
        while(low<high){
            
            int mid = (low+high)/2;
            
            if((is_even(mid) && nums[mid]==nums[mid+1])||(is_odd(mid) && nums[mid]==nums[mid-1]))
                low = mid+1;
            else
                high = mid;
            
        }
        return nums[low];
    }
};