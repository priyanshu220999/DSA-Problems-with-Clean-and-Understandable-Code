class Solution {
    
    bool is_odd(int n){
        return n%2;
    }
    
    int atmostK(vector<int> nums,int n,int k){
        
        if(k==0)
            return 0;
        
        int i = 0,j = 0,l = 0,count = 0,odd = 0;
        
        while(i<n){
            
            if(is_odd(nums[i])){
                
                odd++;
                j=i;
                if(odd<=k)
                    count +=(j-l+1);
                else{
                    while(odd>k){
                        
                        if(is_odd(nums[l]))
                            odd--;
                        l++;
                        if(odd<=k)
                            count+=(j-l+1);
                    }
                }
            }
            else{
                if(odd>0 && odd<=k)
                    count+=(j-l+1);
            }
            i++;
        }
        return count;
    }
    
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        
        int n = nums.size();
        
        if(n==1)
            return is_odd(nums[0])?1:0;
        
        return atmostK(nums,n,k)-atmostK(nums,n,k-1);
    }
};