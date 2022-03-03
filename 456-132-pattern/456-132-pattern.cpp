class Solution {
    
public:
    bool find132pattern(vector<int>& nums) {
        
        int n = nums.size();
        
        if(n<3)
            return false;
        
        stack<int> stk;
        
        int s3 = INT_MIN;
        
        for(int i = n-1;i>=0;i--){
            
            if(nums[i]<s3) return true;
            
            else{
                
                while(!stk.empty() && stk.top()<nums[i]){
                    s3 = stk.top();
                    stk.pop();
                }
            }
            stk.push(nums[i]);
        }
        return false;
    }
};