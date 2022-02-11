class Solution {
    
    bool is_valid(int i,int j,int r,int c){
        return (i>=0 && j>=0 && i<r && j<c);
    }
    
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        int r = matrix.size();
        int c = matrix[0].size();
        
        int i = 0,j = c-1;
        
        while(is_valid(i,j,r,c)){
            
            int cur_ele = matrix[i][j];
            
            if(cur_ele==target)
                return true;
            else if(cur_ele<target)
                i++;
            else
                j--;
        }
        return false;
    }
};