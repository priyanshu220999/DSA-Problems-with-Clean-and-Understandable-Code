class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        int n = s.size();
        
        if(n==0)
            return 0;
        if(n==1)
            return 1;
        
        int result = -1;
        unordered_map<char,int> hash;
        int i = 0,j = 0;
        
        while(j<n){
            
            hash[s[j]]++;
            
            if(hash[s[j]]==1){
                result = max(result,j-i+1);
            }
            else if(hash[s[j]]>1){
                
                while(hash[s[j]]>1){
                    hash[s[i]]--;
                    i++;
                }
            }
            j++;
        }
        return result;
    }
};