// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        
        if(n==1) return 1;
        
        if(isBadVersion(1)) return 1;
        
        long int low = 1,high = n;
        
        long int result = n;
        
        while(low<=high){
            
            int mid = (low+high)/2;
            
            if(isBadVersion(mid)){
                result = mid;
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return result;
    }
};