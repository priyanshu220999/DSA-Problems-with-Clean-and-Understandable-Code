// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
    
    int get_req_size(string str){
        
        unordered_map<char,int> hash;
        
        for(char i:str){
            hash[i]++;
        }
        return hash.size();
    }
    
    public:
    string findSubString(string str)
    {
        // Your code goes here   
        
        int n = str.size();
        if(n==1){
            return str;
        }
        
        unordered_map<char,int> hash;
        int min_length = INT_MAX;
        int k = get_req_size(str);
        
        int i=0,j=0;
        
        while(j<n){
            
            hash[str[j]]++;
            
            int h = hash.size();
            
            if(h==k){
                
                min_length = min(min_length,j-i+1);
                
                while(hash.size()==k){
                    hash[str[i]]--;
                    
                    if(hash[str[i]]==0){
                        hash.erase(str[i]);
                    }
                    i++;
                    if(hash.size()==k){
                        min_length = min(min_length,j-i+1);
                    }
                }
            }
            j++;
        }
        return str.substr(0,min_length);
    }
};

// { Driver Code Starts.
// Driver code
int main() {
    int t;
    cin >> t;
    while (t--) {

        string str;
        cin >> str;
        Solution ob;
        cout << ob.findSubString(str).size() << endl;
    }
    return 0;
}  // } Driver Code Ends