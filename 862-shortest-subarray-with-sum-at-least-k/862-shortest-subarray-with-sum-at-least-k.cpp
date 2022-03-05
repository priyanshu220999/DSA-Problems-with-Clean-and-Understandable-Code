class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        
        int n = nums.size();
        
        if(n==1)
            return nums[0]>=k?1:-1;
        
        deque<long> dq;
        vector<long> b(nums.begin(),nums.end());
        long i = 0,j = 0,res = n,sum = 0;
        
        while(j<n){
            
            if(nums[j]>=k)
                return 1;
            if(j>0)
                b[j]+=b[j-1];
            
            if(b[j]>=k)
                res = min(res,j+1);
            while(!dq.empty() && b[j]-b[dq.front()]>=k){
                res = min(res,j-dq.front());
                dq.pop_front();
            }
            while(!dq.empty() && b[j]<=b[dq.back()])
                dq.pop_back();
            dq.push_back(j);
            j++;
        }
        cout<<b[n-1]<<endl;
        if(res == n && b[n-1]<k)
            return -1;
        
        return res;
    }
};