class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        
        int n = nums.size();
        
        if(n==1){
            return nums[0]==k?1:0;
        }
        
        unordered_map<int,int> hash;
        int sum = 0;
        int count = 0;
        hash[sum]++;
        for(int i=0;i<n;i++){
            
            sum+=nums[i];
            
            if(hash.find(sum-k)!=hash.end())
                count += hash[sum-k];
            
            hash[sum]++;
        }
        
        return count;
    }
};