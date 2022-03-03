class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        
        double result = INT_MIN;
        
        int n = nums.size();
        
        if(k==1)
            return *max_element(nums.begin(),nums.end())/1.0;
        if(n==1)
            return nums[0]/1.0;
        // if(n==k)
        //     return accumulate(nums.begin(),nums.end(),result)/k;
        
        double sum = 0;
        
        for(int i=0;i<n;i++){
            
            if(i<k)
                sum+=nums[i];
            else{
                result = max(result,sum);
                sum+=nums[i];
                sum-=nums[i-k];
            }
        }
        result = max(result,sum);
        return result/k;
    }
};