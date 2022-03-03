class Solution {
    
    bool is_zero_available(vector<int> nums){
        
        for(int i:nums){
            if(i==0)
                return true;
        }
        return false;
    }
    
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        
        int n = nums.size();
        
        if(n==1)
            return nums[0]==goal?1:0;
        
        if(n==goal){
            return is_zero_available(nums)?0:1;
        }
        
        int sum = 0,count = 0;
        unordered_map<int,int> hash;
        hash[sum]++;
        for(int i = 0;i<n;i++){
            
            sum+=nums[i];
            if(hash.find(sum-goal)!=hash.end())
                count +=hash[sum-goal];
            hash[sum]++;
        }
        return count;
    }
};