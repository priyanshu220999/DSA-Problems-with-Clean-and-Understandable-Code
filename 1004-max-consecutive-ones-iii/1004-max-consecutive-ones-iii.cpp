class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        
        int n = nums.size();
        
        if(n==1)
            return 1;
        if(n==k)
            return n;
        
        int zero = 0,i = 0,j = 0,result = 0;
        
        while(j<n){
            
            if(nums[j]==0)
                zero++;
            if(zero<=k)
                result = max(result,j-i+1);
            else{
                while(zero>k){
                    if(nums[i]==0)
                        zero--;
                    i++;
                    if(zero<=k)
                        result = max(result,j-i+1);
                }
            }
            j++;
        }
        return result;
    }
};