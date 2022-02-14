class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        
        int n = nums.size();
        
        if(n<=1 || k%n==0)
            return;
        if(n==2){
            if(k%n==1)
                swap(nums[0],nums[1]);
            return;
        }
        
        k = k%n;
        
        reverse(nums.begin(),nums.begin()+n-k);
        reverse(nums.begin()+n-k,nums.end());
        reverse(nums.begin(),nums.end());
        return;
    }
};