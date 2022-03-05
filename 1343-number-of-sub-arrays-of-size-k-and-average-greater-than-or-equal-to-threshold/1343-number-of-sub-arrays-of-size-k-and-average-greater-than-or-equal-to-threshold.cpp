class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        
        int n = arr.size();
        
        if(n==1)
            return arr[0]>=threshold?1:0;
        
        if(threshold<=1)
            return (n-k+1);
        
        int i = 0,j = 0,sum = 0,count = 0;
        
        while(j<n){
            
            if(j<k)
                sum+=arr[j];
            else{
                if(sum/k>=threshold)
                    count++;
                sum+=arr[j];
                sum-=arr[i++];
            }
            j++;
        }
        if(sum/k>=threshold)
            count++;
        return count;
    }
};