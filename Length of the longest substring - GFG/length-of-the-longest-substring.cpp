// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
    public:
    int longestUniqueSubsttr(string S){
        //code
        
        int n = S.size();
        
        if(n==1)
            return 1;
        vector<int> hash(26,-1);
        
        int i = 0,j = 0,result = 0;
        
        while(j<n){
            
            i = max(i,hash[S[j]-'a']+1);
            
            result = max(result,j-i+1);
            
            hash[S[j]-'a'] = j;
            j++;
        }
        return result;
    }
};

// { Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string str;
		cin>>str;
		Solution ob;
		cout<<ob.longestUniqueSubsttr(str)<<endl;
	}
	return 0;
}  // } Driver Code Ends