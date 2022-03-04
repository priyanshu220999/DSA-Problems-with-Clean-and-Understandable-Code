class Solution {
public:
    int balancedString(string s) {
        
        int n = s.size();
        
        unordered_map<char,int> hash;
        
        int req = n/4;
        
        for(char c:s) hash[c]++;
        
        if(hash['Q']<=req && hash['W']<=req && hash['E']<=req && hash['R']<=req)
            return 0;
        
        int i = 0,j = 0,res = n;
        
        for(;j<n;j++){
            
            hash[s[j]]--;
            
            while(i<n && hash['Q']<=req && hash['W']<=req && hash['E']<=req && hash['R']<=req){
                res = min(res,j-i+1);
                hash[s[i]]++;
                i++;
            }
        }
        return res;
    }
};