class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        
        int n = temperatures.size();
        
        if(n==1)
            return {0};
        
        stack<int> stk;
        vector<int> result(n,0);
        
        for(int i = n-1;i>=0;i--){
            
            while(!stk.empty() && temperatures[stk.top()]<=temperatures[i])
                stk.pop();
            if(!stk.empty())
                result[i] = stk.top()-i;
            stk.push(i);
        }
        return result;
    }
};