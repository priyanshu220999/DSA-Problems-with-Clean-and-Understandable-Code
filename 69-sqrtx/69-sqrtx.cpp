class Solution {
public:
    int mySqrt(int x) {
        
        long long int i = 1;
        long long int j = 1;
        int result =  0;
        
        while(i<=x){
            result++;
            j +=2;
            i+=j;
        }
        return result;
    }
};