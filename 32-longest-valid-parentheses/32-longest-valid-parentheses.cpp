class Solution {
    
    bool is_open(char c){
        return c=='(';
    }
    bool is_close(char c){
        return c==')';
    }
public:
    int longestValidParentheses(string s) {
        
        int n = s.size();
        
        if(n<=1)
            return 0;
        
        stack<int> stk;
        
        stk.push(-1);
        
        int result = 0;
        
        for(int i=0;i<n;i++){
            
            if(is_open(s[i])){
                stk.push(i);
            }
            else{
                if(!stk.empty() && stk.top()==-1){
                    stk.pop();
                    stk.push(i);
                }
                else if(!stk.empty() && is_open(s[stk.top()])){
                    stk.pop();
                    if(!stk.empty())
                        result = max(result,i-stk.top());
                }
                else{
                    stk.push(i);
                }
            }
        }
        return result;
    }
};