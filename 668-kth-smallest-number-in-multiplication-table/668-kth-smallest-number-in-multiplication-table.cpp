class Solution {
    
    int get_count(int m,int n,int mid){
        
        int fin_count = 0;
        
        for(int i=1;i<=m;i++){
            
            int cur_count = min(mid/i,n);
            fin_count += cur_count;
        }
        return fin_count;
    }
    
public:
    int findKthNumber(int m, int n, int k) {
        
        if(k==1 || (m==1 && n==1))
            return 1;
        if(k==m*n)
            return k;
        
        int low = 1,high = m*n,result = 1;
        
        while(low<=high){
            
            int mid = (high-low)/2 + low;
            
            int cur_count = get_count(m,n,mid);
            
            if(cur_count<k)
                low = mid+1;
            else{
                result = mid;
                high = mid-1;
            }
        }
        return result;
    }
};