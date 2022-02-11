class Solution {
    
    void find_max_and_sum(int &maxi,int &sum,vector<int> weights){
        
        for(int i:weights){
            if(i>maxi)
                maxi = i;
            sum+=i;
        }
    }
    
    bool is_valid(int limit,vector<int> weights,int n,int days){
        
        int cur_days = 1;
        int mass = 0;
        
        for(int i = 0;i<n;i++){
            
            if(weights[i]>limit)
                return false;
            else if(weights[i]+mass>limit){
                cur_days++;
                mass = weights[i];
                if(cur_days>days)
                    return false;
            }
            else{
                mass += weights[i];
            }
        }
        return true;
    }
    
public:
    int shipWithinDays(vector<int>& weights, int days) {
        
        int n = weights.size();
        
        if(n==1)
            return weights[0];
        
        int result = -1;
        
        int maxi = INT_MIN,sum = 0;
        
        find_max_and_sum(maxi,sum,weights);
        
        int low = maxi,high = sum;
        
        while(low<=high){
            
            int mid = (low+high)/2;
            
            if(is_valid(mid,weights,n,days)){
                result = mid;
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return result;
    }
};