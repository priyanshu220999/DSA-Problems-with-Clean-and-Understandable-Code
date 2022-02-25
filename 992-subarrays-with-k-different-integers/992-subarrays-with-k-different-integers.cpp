class Solution {
    
    int atmostK(vector<int> nums,int n,int k){
        
        if(k==0)
            return 0;
        
        if(n==k)
            return n*(n+1)/2;
        
        unordered_map<int,int> hash;
        int i = 0,j = 0;
        int count = 0;
        
        while(j<n){
            
            hash[nums[j]]++;
            
            if(hash.size()<=k)
                count += (j-i+1);
            else{
                
                while(i<j && hash.size()>k){
                    hash[nums[i]]--;
                    if(hash[nums[i]]==0)
                        hash.erase(nums[i]);
                    i++;
                    if(hash.size()<=k)
                        count += (j-i+1);
                }
            }
            j++;
        }
        return count;
    }
    
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        
        int n = nums.size();
        
        return atmostK(nums,n,k)-atmostK(nums,n,k-1);
    }
};