class Solution {
    
    bool is_even(int num){
        return num%2==0;
    }
    
public:
    int findMaxLength(vector<int>& nums) {
        
        int n = nums.size();
        
        if(n==1)
            return 0;
        if(n==2)
            return nums[0]==nums[1]?0:2;
        
        unordered_map<int,int> hash;
        int sum = 0,result = 0;
        hash[0] = -1;
        for(int i=0;i<n;i++){
            
            if(nums[i]==0)
                sum-=1;
            else
                sum+=1;
            
            if(hash.find(sum)==hash.end())
                hash[sum] = i;
            else{
                if(is_even(i-hash[sum]))
                    result = max(result,i-hash[sum]);
            }
        }
        return result;
    }
};