class Solution {
public:
    bool judgeSquareSum(int c) {
        
        
        if(c<3) return true;
        if(c%4==3) return false;
        
        double root = sqrt(c);
        
        if(root == int(root)) return true;
        
        for(long long int i = 2;i*i<=c;i++){
            
            long long int count = 0;
            
            if(c%i==0){
                while(c%i==0){
                    count++;
                    c = c/i;
                }
                
                if(i%4==3 && count%2!=0)
                    return false;
            }
        }
        
        return c%4!=3;
    }
};