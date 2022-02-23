class Solution {
    
    bool is_alone(int num,int left,int right,unordered_map<int,int> hash){
        
        if(hash[num]>2)
            return false;
        if(hash.find(left)!=hash.end())
            return false;
        if(hash.find(right)!=hash.end())
            return false;
        return true;
    }
    
public:
    vector<int> findLonely(vector<int>& nums) {
        
        int n = nums.size();
        
        if(n==1){
            return nums;
        }
        
        vector<int> result;
        unordered_map<int,int> hash;
        for(int i=0;i<n;i++){
            hash[nums[i]]++;
        }
        
        for(auto [val,count]:hash){
            
            if(count==1 && hash.count(val+1)==0 && hash.count(val-1)==0)
                result.push_back(val);
        }
        return result;
    }
};