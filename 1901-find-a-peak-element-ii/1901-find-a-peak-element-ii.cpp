class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        
        if(m==1 && n==1) return {0,0};
        
        int low = 0,high = n-1;
        
        while(low<=high){
            
            int mid = (low+high)/2;
            
            int max_row = 0;
            
            for(int i = 0;i<=m-1;i++){
                
                if(mat[max_row][mid]<mat[i][mid])
                    max_row = i;
            }
            
            if((mid==0 || mat[max_row][mid]>mat[max_row][mid-1]) &&
                (mid==n-1 || mat[max_row][mid]>mat[max_row][mid+1]))
                return {max_row,mid};
            else if(mid>0 && mat[max_row][mid]<mat[max_row][mid-1])
                high = mid-1;
            else
                low = mid+1;
        }
        return {-1,-1};
    }
};