class Solution {
    
    bool is_even(int n){
        return abs(n)%2==0;
    }
    
public:
    double myPow(double x, int n) {
        
        if(n==0)
            return 1.0;
        if(n==1)
            return x;
        if(n==-1)
            return 1/x;
        if(x==1.0)
            return 1.0;
        if(x==-1){
            return is_even(n)?-x:x;
        }
        
        if(n>0){
            if(is_even(n)){
                double cur_pow = myPow(x,n/2);
                return cur_pow*cur_pow;
            }
            else{
                double cur_pow = myPow(x,n/2);
                return x*cur_pow*cur_pow;
            }
        }
        else{
            if(is_even(n)){
                double cur_pow = myPow(x,n/2);
                return cur_pow*cur_pow;
            }
            else{
                double cur_pow = myPow(x,n/2);
                return cur_pow*cur_pow/x;
            }
        }
        return 0.0;
    }
};