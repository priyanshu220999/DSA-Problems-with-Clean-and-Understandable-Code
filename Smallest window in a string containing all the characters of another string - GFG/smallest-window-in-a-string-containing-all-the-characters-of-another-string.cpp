// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    unordered_map<char,int> get_p_hash(string p){
        unordered_map<char,int> hash;
        for(char i:p)
            hash[i]++;
        return hash;
    }
    
    public:
    //Function to find the smallest window in the string s consisting
    //of all the characters of string p.
    string smallestWindow (string s, string p)
    {
        // Your code here
        int s_size = s.size();
        int p_size = p.size();
        
        if(s_size<p_size) return "-1";
        
        if(s==p) return s;
        
        unordered_map<char,int> hash = get_p_hash(p);
        string result = "-1";
        int result_size = 0;
        int counter = hash.size();
        
        int i = 0,j = 0;
        
        while(j<s_size){
            
            if(hash.find(s[j])!=hash.end()){
                hash[s[j]]--;
                if(hash[s[j]]==0)
                    counter--;
            }
            if(counter==0){
                
                if(result=="-1"){
                    result = s.substr(i,j-i+1);
                }
                else{
                    result = result.size()>(j-i+1)?s.substr(i,j-i+1):result;
                }
                while(counter==0){
                    
                    if(hash.find(s[i])!=hash.end()){
                        hash[s[i]]++;
                        if(hash[s[i]]>0){
                            counter++;
                        }
                    }
                    i++;
                    if(counter==0)
                        result = result.size()>(j-i+1)?s.substr(i,j-i+1):result;
                }
            }
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
        string s;
        cin>>s;
        string pat;
        cin>>pat;
        Solution obj;
        cout<<obj.smallestWindow(s, pat)<<endl;
        
    }
	return 0;
}  // } Driver Code Ends