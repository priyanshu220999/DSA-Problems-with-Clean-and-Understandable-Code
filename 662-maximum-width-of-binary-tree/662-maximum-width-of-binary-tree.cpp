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
            
            int n = hash.size();
            
            int first,second;
            
            int mmin = hash.front().second;
            
            for(int i=0;i<n;i++){
                
                int cur_id = hash.front().second - mmin;
                
                TreeNode* temp = hash.front().first;
                
                hash.pop();
                
                if(i==0)
                    first = cur_id;
                if(i==n-1)
                    second = cur_id;
                if(temp->left)
                    hash.push({temp->left,cur_id*2ll+1});
                if(temp->right)
                    hash.push({temp->right,cur_id*2ll+2});
            }
            
            result = max(result,second-first+1);
        }
        
        return result;
    }
};