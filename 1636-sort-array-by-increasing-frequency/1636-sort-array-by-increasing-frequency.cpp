class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return nums;
        
        unordered_map<int,int> count;
        
        vector<vector<int>> bucket(n+1);
        
        vector<int> result;
        
        for(int i=0;i<n;i++){
            count[nums[i]]++;
        }
        for(auto &itr: count){
            bucket[itr.second].push_back(itr.first);
        }
        for(int i = 1;i<=n;i++){
            if(!bucket[i].empty()){
                vector<int> temp = bucket[i];
                int m = temp.size();
                sort(temp.begin(),temp.end(),greater<int>());
                for(int j=0;j<m;j++){
                    result.insert(result.end(),i,temp[j]);
                }
            }
        }
        return result;
    }
};