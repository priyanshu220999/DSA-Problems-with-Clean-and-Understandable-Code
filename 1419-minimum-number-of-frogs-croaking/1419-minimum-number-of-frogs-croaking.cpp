class Solution {
public:
    int minNumberOfFrogs(string croakOfFrogs) {
        
        int n = croakOfFrogs.size();
        if(n%5!=0)
            return -1;
        int max_frogs = 0,frogs = 0;
        int cnt[5] = {0};
        string test_str = "croak";
        
        for(auto ch:croakOfFrogs){
            
            auto ind = test_str.find(ch);
            ++cnt[ind];
            
            if(ind==0){
                max_frogs = max(max_frogs,++frogs);
            }
            else if(--cnt[ind-1]<0){
                return -1;
            }
            else if(ind==4){
                frogs--;
            }
        }
        return frogs==0?max_frogs:-1;
    }
};