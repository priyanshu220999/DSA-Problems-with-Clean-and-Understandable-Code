class Solution {
    
public:
    int nthMagicalNumber(int n, int a, int b) {
        
        if(n==1){
            return min(a,b);
        }
        if(a==1 || b==1){
            return n;
        }
        
        long long mod = 1e9+7;
        
        long long lcm = (a*b)/__gcd(a,b);
        
        long long mini = min(a,b);
        
        long long low = mini;
        long long high = n*mini;
        
        while(low<high){
            
            long long mid = (high-low)/2 + low;
            
            long long cur_magical_nums = (mid/a + mid/b - mid/lcm);
            
            if(cur_magical_nums<n){
                low = mid+1;
            }
            else{
                high = mid;
            }
        }
        return low%mod;
    }
};