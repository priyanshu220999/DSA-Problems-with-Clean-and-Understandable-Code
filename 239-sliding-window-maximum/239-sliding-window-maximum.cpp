class Solution {
    
    int get_max(vector<int> nums){
        
        int result = INT_MIN;
        
        for(int i:nums){
            result = max(i,result);
        }
        return result;
    }
    
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        
        int n = nums.size();
        
        if(n==1 || k==1){
            return nums;
        }
        if(k==n){
            return {get_max(nums)};
        }
        
        deque<int> hash;
        vector<int> result;
        int i=0,j=0;
        
        while(j<n){
            
            while(!hash.empty() && hash.back()<nums[j])
                hash.pop_back();
            hash.push_back(nums[j]);
            
            if(j-i+1<k)
                j++;
            else{
                result.push_back(hash.front());
                
                if(hash.front()==nums[i])
                    hash.pop_front();
                i++;
                j++;
            }
        }
        return result;
    }
};