class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        
        int n = letters.size();
        
        if(n==2){
            if(letters[1]<target)
                return letters[0];
            return letters[1];
        }
        
        char result = '#';
        
        int left = 0,right = n-1;
        
        while(left<=right){
            
            int mid = (left+right)/2;
            
            int cur_char = letters[mid];
            
            if(cur_char==target){
                left=mid+1;
            }
            else if(cur_char>target){
                result = cur_char;
                right = mid-1;
            }
            else
                left = mid+1;
        }
        return result=='#'?letters[0]:result;
    }
};