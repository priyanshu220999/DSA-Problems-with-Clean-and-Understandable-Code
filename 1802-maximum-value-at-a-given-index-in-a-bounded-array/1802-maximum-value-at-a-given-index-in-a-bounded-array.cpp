class Solution {
    
    long int get_sum(int n,long int mid,int index){
        
        int l = index;
        
        int r = n-index-1;
        
        long int m = mid-1;
        
        long int ls=0,rs=0;
        
        if(r==m)
            rs = m*(m+1)/2;
        else if(r<m)
            rs = m*(m+1)/2 - (m-r)*(m-r+1)/2;
        else 
            rs = m*(m+1)/2 + (r-m);
        if(l==m)
            ls = m*(m+1)/2;
        else if(l<m)
            ls = m*(m+1)/2 - (m-l)*(m-l+1)/2;
        else 
            ls = m*(m+1)/2 + (l-m);
        
        long int cur_sum = mid+ls+rs;
        
        return cur_sum;
    }
    
public:
    int maxValue(int n, int index, int maxSum) {
        
        if(n==1) return maxSum;
        
        if(n==maxSum) return 1;
        
        long int result = -1;
        
        long int low = 0,high = maxSum;
        
        while(low<=high){
            
            long int mid = (low+high)/2;
            
            long int cur_sum = get_sum(n,mid,index);
            
            if(cur_sum<=maxSum){
                result = mid;
                low = mid+1;
            }
            else
                high = mid-1;
        }
        return result;
    }
};