class Solution {
public:
    int minimizedMaximum(int n, vector<int>& quantities) {
        
        int low = 1,high = 100000;
        
        while(low<high){
            
            int mid = (low+high)/2,sum = 0;
            
            for(int i:quantities){
                sum += (i+mid-1)/mid;
            }
            
            if(n<sum){
                low = mid+1;
            }
            else{
                high= mid;
            }
        }
        return low;
    }
};