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
    vector<vector<int>> levelOrder(TreeNode* root) {
        
        vector<vector<int>> result;
        
        if(!root)
            return result;
        
        queue<TreeNode*> hash;
        
        hash.push(root);
        
        while(!hash.empty()){
            
            int size = hash.size();
            
            vector<int> level;
            
            for(int i=0;i<size;i++){
                
                TreeNode *temp = hash.front();
                
                hash.pop();
                
                if(temp->left)
                    hash.push(temp->left);
                if(temp->right)
                    hash.push(temp->right);
                level.push_back(temp->val);
            }
            result.push_back(level);
        }
        
        return result;
    }
};