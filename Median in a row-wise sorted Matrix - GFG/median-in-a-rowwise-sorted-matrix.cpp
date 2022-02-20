// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++

class Solution{
    
    bool is_even(int n){
        return n%2==0;
    }
    
    int smaller_or_equal(vector<vector<int>> mat,int r, int c,int check){
        
        int count = 0;
        
        for(int i=0;i<r;i++){
            
            int low = 0,high = c-1,result = -1;
            
            while(low<=high){
                
                int mid = (high-low)/2 + low;
                
                int cur_ele = mat[i][mid];
                
                if(cur_ele<=check){
                    result = mid;
                    low = mid+1;
                }
                else{
                    high = mid-1;
                }
            }
            count += (result+1);
        }
        return count;
    }
    
public:
    int median(vector<vector<int>> &matrix, int r, int c){
        // code here 
        
        if(r==1 && c==1){
            return matrix[0][0];
        }
        if(r==1 && c==2){
            return (matrix[0][0]+matrix[0][1])/2;
        }
        if(r==2 && c==1){
            return (matrix[0][0]+matrix[1][0])/2;
        }
        
        int low = 1,high = 2000;
        int med = matrix[0][0];
        
        int req_count;
        
        if(is_even(r*c)) req_count = (r*c)/2;
        else req_count = (r*c)/2 + 1;
        
        while(low<=high){
            
            int mid = (high-low)/2 + low;
            
            int count = smaller_or_equal(matrix,r,c,mid);
            
            if(count>=(req_count)){
                med = mid;
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return med;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int r, c;
        cin>>r>>c;
        vector<vector<int>> matrix(r, vector<int>(c));
        for(int i = 0; i < r; ++i)
            for(int j = 0;j < c; ++j)
                cin>>matrix[i][j];
        Solution obj;
        cout<<obj.median(matrix, r, c)<<endl;        
    }
    return 0;
}  // } Driver Code Ends