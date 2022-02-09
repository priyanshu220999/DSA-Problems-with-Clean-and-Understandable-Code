class Solution {
    
    int count = 0;
    
    int min_count = 0;
    
    int max_count = 0;
    
    int get_min(vector<int> nums){
        
        int result = INT_MAX;
        
        for(int i:nums){
            
            if(i<result)
                result = i;
        }
        return result;
    }
    
    int get_max(vector<int> nums){
        int result = INT_MIN;
        
        for(int i:nums){
            
            if(i>result)
                result = i;
        }
        return result;
    }
    
    void count_func(vector<int> nums,int &count,int &max_count,int &min_count,int min_ele,int max_ele){
        
        for(int i:nums){
            
            count++;
            
            if(i == min_ele)
                min_count++;
            else if(i == max_ele)
                max_count++;
        }
    }
    
public:
    int countElements(vector<int>& nums) {
        
        int min_ele = get_min(nums);
        int max_ele = get_max(nums);
        
        count_func(nums,count,max_count,min_count,min_ele,max_ele);
        
        if(max_count==count || count == max_count+min_count) return 0;
        
        int result = count - max_count - min_count;
        
        return result;
    }
};