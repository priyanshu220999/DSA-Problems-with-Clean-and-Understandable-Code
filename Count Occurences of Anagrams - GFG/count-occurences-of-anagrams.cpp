// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


 // } Driver Code Ends
//User function template for C++
class Solution{
public:
	int search(string pat, string txt) {
	    // code here
	    
	    int count = 0;
	    
	    vector<int> p_hash(26,0);
	    vector<int> t_hash(26,0);
	    
	    int p_size = pat.size();
	    int t_size = txt.size();
	    
	    int i=0,j=0;
	    
	    for(;j<p_size;j++){
	        p_hash[pat[j]-97]++;
	        t_hash[txt[j]-97]++;
	    }
	    if(p_hash==t_hash) count++;
	    
	    while(i<t_size && j<t_size){
	        
	        t_hash[txt[i]-97]--;
	        t_hash[txt[j]-97]++;
	        
	        if(t_hash==p_hash){
	            count++;
	        }
	        i++;
	        j++;
	    }
	    return count;
	}

};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string pat, txt;
        cin >> txt >> pat;
        Solution ob;
        auto ans = ob.search(pat, txt);
        cout << ans << "\n";
    }
    return 0;
}  // } Driver Code Ends