class Solution {
public:
    int numberOfSubstrings(string s) {
        
        int n = s.size();
        
        unordered_map<char,int> hash{{'a',0},{'b',0},{'c',0}};
        
        int i = 0,j = 0;
        int count = 0;
        for(;j<n;j++){
            
            hash[s[j]]++;
            
            while(hash['a'] && hash['b'] && hash['c']){
                hash[s[i]]--;
                i++;
            }
            count +=i;
        }
        return count;
    }
};