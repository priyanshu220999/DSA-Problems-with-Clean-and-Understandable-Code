class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        
        int n = nums.size();
        
        if(n==1){
            return nums[0];
        }
        
        unordered_map<int,int> hash;
        int sum = 0,result = 0;
        int i = 0,j = 0;
        
        while(j<n){
            
            hash[nums[j]]++;
            
            if(hash[nums[j]]==1){
                sum += nums[j];
            }
            else if(hash[nums[j]]>1){
                
                result = max(sum,result);
                
                while(hash[nums[j]]>1){
                    
                    hash[nums[i]]--;
                    sum-=nums[i];
                    i++;
                }
                sum+=nums[j];
            }
            j++;
        }
        result = max(sum,result);
        return result;
    }
};