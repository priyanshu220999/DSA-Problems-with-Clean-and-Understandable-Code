class Solution {
    
    void find_max_and_sum(vector<int> nums,int &sum,int &maxi){
        
        for(int i:nums){
            sum+=i;
            if(maxi<i)
                maxi = i;
        }
    }
    
    bool is_valid(int limit,vector<int> nums,int n,int m){
        
        int sum = 0;
        int partitions = 1;
        
        for(int i = 0;i<n;i++){
            
            if(nums[i]>limit)
                return false;
            else if(nums[i]+sum>limit){
                partitions++;
                sum = nums[i];
                if(partitions>m)
                    return false;
            }
            else{
                sum +=nums[i];
            }
        }
        return true;
    }
    
public:
    int splitArray(vector<int>& nums, int m) {
        
        int n = nums.size();
        
        if(n==1)
            return nums[0];
        
        int sum = 0,maxi = INT_MIN,result = -1;
        
        find_max_and_sum(nums,sum,maxi);
        
        int low = maxi,high = sum;
        
        while(low<=high){
            
            int mid = (low+high)/2;
            
            if(is_valid(mid,nums,n,m)){
                result = mid;
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return result;
    }
};