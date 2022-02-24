class Solution {
    
    unordered_map<char,int> get_t_hash(string t){
        
        unordered_map<char,int> hash;
        
        for(char i:t)
            hash[i]++;
        
        return hash;
    }
    
public:
    string minWindow(string s, string t) {
        
        int t_size = t.size();
        int s_size = s.size();
        
        if(t_size>s_size)
            return "";
        if(t==s)
            return s;
        
        unordered_map<char,int> hash = get_t_hash(t);
        
        int count = hash.size();
        string result = "";
        int i = 0,j = 0;
        
        while(j<s_size){
            
            if(hash.find(s[j])!=hash.end()){
                hash[s[j]]--;
                if(hash[s[j]]==0)
                    count--;
            }
            if(count == 0){
                
                if(result=="")
                    result = s.substr(i,j-i+1);
                else
                    result = result.size()>(j-i+1)?s.substr(i,j-i+1):result;
                while(count==0){
                    
                    if(hash.find(s[i])!=hash.end()){
                        hash[s[i]]++;
                        if(hash[s[i]]>0)
                            count++;
                    }
                    i++;
                    if(count==0)
                        result = result.size()>(j-i+1)?s.substr(i,j-i+1):result;
                }
            }
            j++;
        }
        return result;
    }
};