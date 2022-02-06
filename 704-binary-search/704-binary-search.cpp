class Solution {
public:
    int search(vector<int>& nums, int target) {
        
        int n = nums.size();
        
        if(n==1)
            return nums[0]==target?0:-1;
        
        int begin = 0,end = n-1;
        
        while(begin<=end){
            
            int mid = (begin+end)/2;
            
            int cur_element = nums[mid];
            
            if(cur_element==target)
                return mid;
            else if(cur_element<target)
                begin = mid+1;
            else
                end = mid-1;
                
        }
        return -1;
    }
};