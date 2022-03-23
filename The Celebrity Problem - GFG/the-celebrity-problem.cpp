// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution 
{
    bool is_celebrity(int c,vector<vector<int>> &m,int n){
        
        for(int i=0;i<n;i++){
            if(i!=c && (m[i][c]==0 || m[c][i]==1))
                return false;
        }
        return true;
    }
    
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) 
    {
        // code here 
        stack<int> stk;
        
        for(int i=0;i<n;i++){
            stk.push(i);
        }
        
        while(stk.size()>1){
            
            int human1 = stk.top();
            stk.pop();
            int human2 = stk.top();
            stk.pop();
            if(M[human1][human2]==1){
                stk.push(human2);
            }
            else{
                stk.push(human1);
            }
        }
        return is_celebrity(stk.top(),M,n)?stk.top():-1;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<vector<int> > M( n , vector<int> (n, 0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>M[i][j];
            }
        }
        Solution ob;
        cout<<ob.celebrity(M,n)<<endl;

    }
}
  // } Driver Code Ends