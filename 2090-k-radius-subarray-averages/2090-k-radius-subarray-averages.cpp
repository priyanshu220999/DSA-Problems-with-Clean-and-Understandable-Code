class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        
        long int n = nums.size();
        vector<int> result(n,-1);
        if(n<k)
            return vector<int>(n,-1);
        if(k==0)
            return nums;
        if(n==1)
            return k==0?nums:result;
        
        long int limit = (2*k)+1;
        
        if(limit>n)
            return result;
        
        long int sum = 0,i;
        
        for(i=0;i<n;i++){
            
            if(i<limit)
                sum+=nums[i];
            else{
                result[i-k-1] = sum/limit;
                sum+=nums[i];
                sum-=nums[i-limit];
            }
        }
        result[i-k-1] = sum/limit;
        return result;
    }
};