class Solution {
    
    vector<int> get_next_smaller(vector<int> &heights,int n){
        
        stack<int> stk;
        vector<int> result(n,n);
        
        for(int i = n-1;i>=0;i--){
            
            while(!stk.empty() && heights[stk.top()]>=heights[i])
                stk.pop();
            if(!stk.empty())
                result[i] = stk.top();
            stk.push(i);
        }
        return result;
    }
    
    vector<int> get_prev_smaller(vector<int> &heights,int n){
        
        stack<int> stk;
        vector<int> result(n,-1);
        
        for(int i = 0;i<n;i++){
            
            while(!stk.empty() && heights[stk.top()]>=heights[i])
                stk.pop();
            if(!stk.empty())
                result[i] = stk.top();
            stk.push(i);
        }
        return result;
    }
    
public:
    int largestRectangleArea(vector<int>& heights) {
        
        int n = heights.size();
        
        if(n==1){
            return heights[0];
        }
        
        vector<int> next_smaller = get_next_smaller(heights,n);
        vector<int> prev_smaller = get_prev_smaller(heights,n);
        
        int max_area = 0;
        
        for(int i = 0;i<n;i++){
            
            int breadth = (next_smaller[i]-prev_smaller[i]-1);
            
            int cur_area = heights[i]*breadth;
            
            max_area = max(max_area,cur_area);
        }
        return max_area;
    }
};