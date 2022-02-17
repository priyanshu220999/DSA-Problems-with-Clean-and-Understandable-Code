class Solution {
public:
    int countPrimes(int n) {
        
        if(n==2)
            return 0;
        
        vector<bool> primes(n,true);
        
        long int count = 0;
        
        for(long int i=2;i*i<n;i++){
            
            if(primes[i]){
                
                for(long int j = i*i;j<n;j+=i){
                    primes[j] = false;
                }
                
            }
            
        }
        
        for(long int i = 2;i<n;i++){
            if(primes[i]){
                count++;
            }
        }
        return count;
    }
};