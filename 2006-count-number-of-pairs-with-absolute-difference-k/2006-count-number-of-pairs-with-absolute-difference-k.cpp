class Solution {
public:
    int countKDifference(vector<int>& nums, int k) {
        
        int n = nums.size();
        
        if(n==1)
            return 0;
        int count = 0;
        unordered_map<int,int> hash;
        
        for(int i=0;i<n;i++){
            
            hash[nums[i]]++;
            
            if(hash.find(nums[i]-k)!=hash.end())
                count +=hash[nums[i]-k];
            if(hash.find(nums[i]+k)!=hash.end())
                count+=hash[nums[i]+k];
            
        }
        return count;
    }
};