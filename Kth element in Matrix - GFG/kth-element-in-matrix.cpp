// { Driver Code Starts
// kth largest element in a 2d array sorted row-wise and column-wise
#include<bits/stdc++.h>
using namespace std;
#define MAX 1000
int mat[MAX][MAX];
int kthSmallest(int mat[MAX][MAX], int n, int k);
// driver program to test above function
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
    
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                cin>>mat[i][j];
        int r;
        cin>>r;
        cout<<kthSmallest(mat,n,r)<<endl;
    }
     // cout << "7th smallest element is " << kthSmallest(mat, 4, 7);
      return 0;
}
// } Driver Code Ends

int less_or_equal(int mat[MAX][MAX],int n,int check){
    
    int count = 0;
    
    for(int i = 0;i<n;i++){
        
        int low = 0,high = n-1,result = -1;
        
        while(low<=high){
            
            int mid = (high-low)/2 + low;
            
            int cur_num = mat[i][mid];
            
            if(cur_num<=check){
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

int kthSmallest(int mat[MAX][MAX], int n, int k)
{
    if(n==1 || k==1){
        return mat[0][0];
    }
    if(k==n*n){
        return mat[n-1][n-1];
    }
    
    int low = mat[0][0],high = mat[n-1][n-1],result = -1;
    
    while(low<=high){
        
        int mid = (high-low)/2 + low;
        
        int count = less_or_equal(mat,n,mid);
        
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
