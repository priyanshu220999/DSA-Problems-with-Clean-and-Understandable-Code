class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        
        int n = fruits.size();
        
        if(n<=2)
            return n;
        
        unordered_map<int,int> hash;
        
        int i = 0,j = 0,result = 0;
        
        while(j<n){
            
            hash[fruits[j]]++;
            
            if(hash.size()<=2)
                result = max(result,j-i+1);
            else{
                while(hash.size()>2){
                    hash[fruits[i]]--;
                    if(hash[fruits[i]]==0)
                        hash.erase(fruits[i]);
                    i++;
                    if(hash.size()<=2)
                        result = max(result,j-i+1);
                }
            }
            j++;
        }
        return result;
    }
};