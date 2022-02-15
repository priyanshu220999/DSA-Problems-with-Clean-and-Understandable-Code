class Solution {
public:
    int mySqrt(int x) {
        
        if(x<2)
            return x;
        if(x<4)
            return 1;
        if(x<9)
            return 2;
        
        int low = 1,high = x;
        
        while(low<high){
            
            int mid = (high-low)/2 + low;
            
            int div = x/mid;
            
            if(div==mid)
                return mid;
            else if(div<mid)
                high = mid;
            else
                low = mid+1;
        }
        
        // if(x/high>=high)
        //     return high;
        return low-1;
    }
};