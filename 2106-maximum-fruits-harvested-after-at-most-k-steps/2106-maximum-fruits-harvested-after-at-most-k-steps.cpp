class Solution {
public:
    int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {
        
        int mx = 2e5 + 1;
        int n = fruits.size();
        vector<int> prefix(mx);
        
        for(auto it:fruits){
            prefix[it[0]] = it[1];
        }
        for(int i = 1;i<mx;i++){
            prefix[i]+=prefix[i-1];
        }
        
        int maxi = 0;
        
        for(int i = startPos;i<=min(mx-1,startPos+k);i++){
            
            int r = i;
            int x = i-startPos;
            int l = startPos -(k-2*x);
            l = min(l,startPos);
            
            int sum = prefix[r];
            if(l>0)
                sum-=prefix[l-1];
            
            maxi = max(maxi,sum);
        }
        
        for(int i = startPos;i>=max(0,startPos-k);i--){
            
            int l = i;
            int x = startPos-i;
            int r = startPos+(k-2*x);
            r = max(min(r,mx-1),startPos);
            int sum = prefix[r];
            if(l>0)
                sum-=prefix[l-1];
            
            maxi = max(maxi,sum);
        }
        
        return maxi;
    }
};