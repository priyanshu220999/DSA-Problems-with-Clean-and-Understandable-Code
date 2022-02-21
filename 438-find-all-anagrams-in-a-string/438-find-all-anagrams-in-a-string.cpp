class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        
        vector<int> result;
        
        int p_size = p.size();
        int s_size = s.size();
        
        if(p_size>s_size){
            return result;
        }
        
        vector<int> s_hash(26,0);
        vector<int> p_hash(26,0);
        
        int i = 0,j = 0;
        
        for(;j<p_size;j++){
            p_hash[p[j]-97]++;
            s_hash[s[j]-97]++;
        }
        if(p_hash==s_hash){
            result.push_back(i);
        }
        
        while(j<s_size){
            
            s_hash[s[i++]-97]--;
            s_hash[s[j++]-97]++;
            
            if(s_hash==p_hash){
                result.push_back(i);
            }
        }
        return result;
    }
};