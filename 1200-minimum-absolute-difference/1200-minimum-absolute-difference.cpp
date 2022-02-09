class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        
        vector<vector<int>> result;
        
        int n = arr.size();
        
        if(n==2){
            result.push_back(arr);
            return result;
        }
        
        int min_diff = INT_MAX;
        
        sort(arr.begin(),arr.end());
        
        for(int i = 0;i<n-1;i++){
            
            int cur_diff = abs(arr[i]-arr[i+1]);
            
            if(min_diff>cur_diff){
                min_diff = cur_diff;
            }
        }
        
        for(int i = 0;i<n-1;i++){
            
            int cur_diff = abs(arr[i]-arr[i+1]);
            
            if(cur_diff == min_diff){
                
                vector<int> cur_pair = {arr[i],arr[i+1]};
                
                result.push_back(cur_pair);
            }
        }
        return result;
    }
};