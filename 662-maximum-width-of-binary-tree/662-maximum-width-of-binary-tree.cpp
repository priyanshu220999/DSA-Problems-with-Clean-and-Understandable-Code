/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        
        if(!root)
            return 0;
        
        int result = 0;
        
        queue<pair<TreeNode*,int>> hash;
        
        hash.push({root,0});
        
        while(!hash.empty()){
            
            int minAtLevel = hash.front().second;
            int n = hash.size();
            
            int mn,mx;
            
            for(int i=0;i<n;i++){
                
                int curIndex = hash.front().second - minAtLevel;
                
                TreeNode* temp = hash.front().first;
                
                hash.pop();
                
                if(i==0)
                    mn = curIndex;
                if(i==n-1)
                    mx = curIndex;
                
                if(temp->left)
                    hash.push({temp->left,2ll*curIndex+1});
                if(temp->right)
                    hash.push({temp->right,2ll*curIndex+2});
            }
            result = max(result,mx-mn+1);
        }
        
        return result;
    }
};