class Solution {
    
    bool is_valid(vector<int> bloomDay,int n,int m,int k,int cur_day){
        
        int total = 0,flow = 0;
        
        for(int i = 0;i<n;i++){
            
            if(bloomDay[i]>cur_day){
                flow = 0;
            }
            else
                flow++;
            if(flow==k){
                total++;
                flow = 0;
            }
            
        }
        return total>=m;
    }
    
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        
        int n = bloomDay.size();
        
        int result = -1;
        
        if(m*k>n) return -1;
        
        int low = 0,high = 1e9;
        
        while(low<=high){
            
            int mid = (low+high)/2;
            
            if(is_valid(bloomDay,n,m,k,mid)){
                
                result = mid;
                high = mid-1;
            }
            else
                low = mid+1;
        }
        return result;
    }
};