class Solution {
    
    vector<int> get_left_greater(vector<int> &height,int n){
        
        stack<int> stk;
        
        vector<int> result(n);
        
        for(int i = 0;i<n;i++){
            
            while(!stk.empty() && stk.top()<=height[i])
                stk.pop();
            
            result[i] = stk.empty()?height[i]:stk.top();
            
            if(stk.empty() || stk.top()<height[i])
                stk.push(height[i]);
        }
        return result;
    }
    
    vector<int> get_right_greater(vector<int> &height,int n){
        
        stack<int> stk;
        
        vector<int> result(n);
        
        for(int i = n-1;i>=0;i--){
            
            while(!stk.empty() && stk.top()<=height[i])
                stk.pop();
            
            result[i] = stk.empty()?height[i]:stk.top();
            
            if(stk.empty() || stk.top()<height[i])
                stk.push(height[i]);
        }
        return result;
    }
    
public:
    int trap(vector<int>& height) {
        
        int n = height.size();
        
        if(n<=2) 
            return 0;
        
        vector<int> left_greater = get_left_greater(height,n);
        vector<int> right_greater = get_right_greater(height,n);
        
        long int area = 0;
        
        for(int i = 0;i<n;i++){
            
            area+=(min(left_greater[i],right_greater[i])-height[i]);
        }
        return area;
    }
};