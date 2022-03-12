class Solution {
    
    void update_histo(vector<int> &histo,int c,vector<vector<char>> &mat,int i){
        
        for(int j = 0;j<c;j++){
            
            if(mat[i][j]=='0')
                histo[j] = 0;
            else
                histo[j]++;
        }
    }
    
    vector<int> get_left_boundary(vector<int> &histo,int n){
        
        stack<int> stk;
        vector<int> result(n,-1);
        
        for(int i=0;i<n;i++){
            
            while(!stk.empty() && histo[stk.top()]>=histo[i])
                stk.pop();
            if(!stk.empty())
                result[i] = stk.top();
            stk.push(i);
        }
        return result;
    }
    
    vector<int> get_right_boundary(vector<int> &histo,int n){
        
        stack<int> stk;
        vector<int> result(n,n);
        
        for(int i=n-1;i>=0;i--){
            
            while(!stk.empty() && histo[stk.top()]>=histo[i])
                stk.pop();
            if(!stk.empty())
                result[i] = stk.top();
            stk.push(i);
        }
        return result;
    }
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        
        int r = matrix.size();
        int c = matrix[0].size();
        
        if(r==1 && c==1){
            return matrix[0][0]=='1'?1:0;
        }
        
        vector<int> histo(c,0);
        
        int max_area = 0;
        
        for(int i = 0;i<r;i++){
            
            update_histo(histo,c,matrix,i);
            vector<int> left = get_left_boundary(histo,c);
            vector<int> right = get_right_boundary(histo,c);
            
            for(int j = 0;j<c;j++){
                max_area = max(max_area,histo[j]*(right[j]-left[j]-1));
            }
        }
        return max_area;
    }
};