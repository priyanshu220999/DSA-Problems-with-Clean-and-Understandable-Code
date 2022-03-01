class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        
        int n = answerKey.size();
        
        if(n==1)
            return 1;
        if(n==k)
            return k;
        int result = 0;
        int i = 0,j = 0,max_count = 0;
        unordered_map<char,int> hash = {{'T',0},{'F',0}};
        
        while(j<n){
            
            hash[answerKey[j]]++;
            
            max_count = max(max_count,hash[answerKey[j]]);
            
            while(j-i+1-max_count>k){
                hash[answerKey[i]]--;
                i++;
            }
            result = max(result,j-i+1);
            j++;
        }
        return result;
    }
};