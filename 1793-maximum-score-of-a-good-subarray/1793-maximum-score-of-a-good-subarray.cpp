class Solution {
    
    vector<int> get_next_smaller(vector<int> &nums,int n){
        
        stack<int> stk;
        vector<int> result(n,n);
        
        for(int i = n-1;i>=0;i--){
            
            while(!stk.empty() && nums[stk.top()]>=nums[i])
                stk.pop();
            if(!stk.empty())
                result[i] = stk.top();
            stk.push(i);
        }
        return result;
    }
    
    vector<int> get_prev_smaller(vector<int> &nums,int n){
        
        stack<int> stk;
        vector<int> result(n,-1);
        
        for(int i = 0;i<n;i++){
            
            while(!stk.empty() && nums[stk.top()]>=nums[i])
                stk.pop();
            if(!stk.empty())
                result[i] = stk.top();
            stk.push(i);
        }
        return result;
    }
    
public:
    int maximumScore(vector<int>& nums, int k) {
        
        int n = nums.size();
        
        if(n==1)
            return nums[0];
        
        vector<int> next_smaller = get_next_smaller(nums,n);
        vector<int> prev_smaller = get_prev_smaller(nums,n);
        
        int max_score = 0;
        
        for(int i = 0;i<n;i++){
            
            if(next_smaller[i]-1>=k && prev_smaller[i]+1<=k){
                
                int breadth = next_smaller[i]-prev_smaller[i]-1;

                int cur_score = nums[i]*breadth;

                max_score = max(max_score,cur_score);
            }
        }
        return max_score;
    }
};