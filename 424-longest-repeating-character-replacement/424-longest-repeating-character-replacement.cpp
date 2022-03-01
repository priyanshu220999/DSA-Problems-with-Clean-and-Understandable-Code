class Solution {
public:
    int characterReplacement(string s, int k) {
        
        int n = s.size();
        
        if(n==1)
            return 1;
        
        if(n==k)
            return k;
        unordered_map<char,int> hash;
        int i = 0,j = 0,result = 0,max_count = 0;
        
        while(j<n){
            
            hash[s[j]]++;
            
            max_count = max(max_count,hash[s[j]]);
            
            while(j-i+1-max_count>k){
                
                hash[s[i]]--;
                i++;
            }
            result = max(result,j-i+1);
            j++;
        }
        return result;
    }
};