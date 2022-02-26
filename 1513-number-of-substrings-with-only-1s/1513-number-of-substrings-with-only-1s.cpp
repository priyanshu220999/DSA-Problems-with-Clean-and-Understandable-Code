class Solution {
public:
    int numSub(string s) {
        
        int n = s.size();
        
        if(n==1)
            return s[0]=='1'?1:0;
        
        int result = 0,count = 0,mod = 1e9+7;
        
        for(int i = 0;i<n;i++){
            
            count = s[i]=='1'?count+1:0;
            
            result = (result+count)%mod;
            
        }
        return result;
    }
};