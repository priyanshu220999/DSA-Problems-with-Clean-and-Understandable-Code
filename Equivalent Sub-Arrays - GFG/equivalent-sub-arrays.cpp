// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
public:
    int countDistinctSubarray(int arr[], int n)
    {
        //code here.
        if(n==1){
            return 1;
        }
        
        unordered_map<int,int> hash1,hash2;
        
        for(int i=0;i<n;i++){
            hash1[arr[i]]++;
        }
        
        int count = hash1.size(),result = 0,i = 0,j = 0;
        
        for(;j<n;j++){
            
            hash2[arr[j]]++;
            
            if(hash2.size()==count){
                result+=(n-j);
                
                do{
                    hash2[arr[i]]--;
                    if(hash2[arr[i]]==0)
                        hash2.erase(arr[i]);
                    i++;
                    if(hash2.size()==count){
                        result +=(n-j);
                    }
                }while(hash2.size()==count);
            }
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
		int n;
		cin>>n;
		int a[n];
		for(int i=0;i<n;++i)
			cin>>a[i];
		Solution ob;	
		cout<<ob.countDistinctSubarray(a,n)<<endl;
	}
	return 0;
}  // } Driver Code Ends