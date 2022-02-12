class Solution {
public:
    bool isPerfectSquare(int num) {
        
        if(num==1 || num==4 || num==9) return true;
        
        long long int low = 1,high = num;
        
        while(low<=high){
            
            long long int mid = (low+high)/2;
            
            long long int cur_square = mid*mid;
            
            if(cur_square==num)
                return true;
            else if(cur_square<num)
                low = mid+1;
            else 
                high = mid-1;
        }
        return false;
    }
};