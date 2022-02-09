class Solution {
    
//     int count = 0;
    
//     int min_count = 0;
    
//     int max_count = 0;
    
//     int get_min(vector<int> nums){
        
//         int result = INT_MAX;
        
//         for(int i:nums){
            
//             if(i<result)
//                 result = i;
//         }
//         return result;
//     }
    
//     int get_max(vector<int> nums){
//         int result = INT_MIN;
        
//         for(int i:nums){
            
//             if(i>result)
//                 result = i;
//         }
//         return result;
//     }
    
//     void count_func(vector<int> nums,int &count,int &max_count,int &min_count,int min_ele,int max_ele){
        
//         for(int i:nums){
            
//             count++;
            
//             if(i == min_ele)
//                 min_count++;
//             else if(i == max_ele)
//                 max_count++;
//         }
//     }
    
public:
    int countElements(vector<int>& nums) {
        
        int n = nums.size();
        
        if(nums.size()<=2)
            return 0;
        
        sort(nums.begin(),nums.end());
        
        if(nums[0]==nums[n-1]) return 0;
        
        int min_ele = nums[0],max_ele = nums[n-1];
        
        int min_count = 0,max_count = 0;
        
        for(int i:nums){
            if(i==min_ele)
                min_count++;
            else if(i==max_ele)
                max_count++;
        }
        
        int result = n - max_count - min_count;
        
        return result;
    }
};