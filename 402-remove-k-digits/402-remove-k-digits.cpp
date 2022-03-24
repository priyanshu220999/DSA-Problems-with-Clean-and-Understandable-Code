class Solution {
public:
    string removeKdigits(string num, int k) {
        
        int n = num.size();
        
        if(k==n || n==1)
            return "0";
        
        string result = "";
        
        stack<char> stk;
        
        for(int i = 0;i<n;i++){
            
            while(!stk.empty() && stk.top()>num[i] && k){
                stk.pop();
                k--;
            }
            
            if((stk.empty() && num[i]!='0') || !stk.empty()){
                stk.push(num[i]);
            }
        }
        
        while(!stk.empty() && k){
            stk.pop();
            k--;
        }
        
        if(stk.empty())
            return "0";
        
        while(!stk.empty()){
            result += stk.top();
            stk.pop();
        }
        
        reverse(result.begin(),result.end());
        
        return result;
    }
};