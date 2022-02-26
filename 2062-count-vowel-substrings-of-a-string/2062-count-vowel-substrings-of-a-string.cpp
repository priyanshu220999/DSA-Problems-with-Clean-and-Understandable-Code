class Solution {
    
    int req_size = 5;
    
    bool is_vowel(char letter){
        
        return letter=='a' || letter=='e' || letter=='i' || letter=='o' || letter=='u';
        
    }
    
public:
    int countVowelSubstrings(string word) {
        
        int n = word.size();
        
        if(n<5)
            return 0;
        
        unordered_map<char,int> hash = {{'a',0},{'e',0},{'i',0},{'o',0},{'u',0}};
        
        int i = 0,j = 0,k = 0,count = 0,vow = 0;
        
        while(i<n){
            
            if(is_vowel(word[i])){
                hash[word[i]]++;
                if(hash[word[i]]==1){
                    vow++;
                }
                for(;vow==5;k++){
                    if(is_vowel(word[k]))
                        hash[word[k]]--;
                    if(hash[word[k]]==0)
                        vow--;
                }
                count += k-j;
            }
            else{
                hash['a'] = hash['e'] = hash['i'] = hash['o'] = hash['u'] = vow = 0;
                j = k = i+1;
            }
            i++;
        }
        
        return count;
    }
};