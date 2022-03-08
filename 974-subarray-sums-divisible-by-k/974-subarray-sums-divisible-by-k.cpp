class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        
        int n = nums.size();
        
        if(n==1)
            return nums[0]%k==0?1:0;
        
        unordered_map<int,int> hash;
        hash[0] = 1;
        int count = 0,sum = 0;
        
        for(int i = 0;i<n;i++){
            
            sum+=nums[i];
            
            if(hash.find(((sum%k)+k)%k)!=hash.end()){
                count+=hash[((sum%k)+k)%k];
            }
            hash[((sum%k)+k)%k]++;
        }
        return count;
    }
};