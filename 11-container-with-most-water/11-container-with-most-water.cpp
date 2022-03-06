class Solution {
public:
    int maxArea(vector<int>& height) {
        
        int n = height.size();
        
        int i = 0,j = n-1,result = 0;
        
        while(i<j){
            
            int wall_height = min(height[i],height[j]);
            
            int area = wall_height*(j-i);
            
            if(area>result)
                result = area;
            
            if(height[i]<height[j])
                i++;
            else
                j--;
        }
        return result;
    }
};