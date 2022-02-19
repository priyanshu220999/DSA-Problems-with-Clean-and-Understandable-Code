class Solution {
    
    int smaller_than_mid(vector<vector<int>> mat,bool &flag,int n,int mid){
        
        int count = 0;
        
        for(int i=0;i<n;i++){
            
            int l = 0,h = n-1,result = -1;
            
            while(l<=h){
                int m = (h-l)/2 + l;
                
                if(mat[i][m]<=mid){
                    
                    if(mat[i][m]==mid)
                        flag = true;
                    result = m;
                    l = m+1;
                }
                else{
                    h = m-1;
                }
            }
            count+=(result+1);
        }
        return count;
    }
    
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        
        int n = matrix.size();
        
        if(n==1){
            return matrix[0][0];
        }
        
        if(k==1){
            return matrix[0][0];
        }
        if(k==n*n){
            return matrix[n-1][n-1];
        }
        
        int low = matrix[0][0],high = matrix[n-1][n-1],result = -1;
        
        while(low<=high){
            
            int mid = (high-low)/2 + low;
            bool flag = false;
            int count = smaller_than_mid(matrix,flag,n,mid);
            
            if(count>=k){
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