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
    
    void solve(vector<int> &result,TreeNode* root){
        
        if(!root)
            return;
        result.push_back(root->val);
        solve(result,root->left);
        solve(result,root->right);
    }
    
public:
    vector<int> preorderTraversal(TreeNode* root) {
        
        if(!root)
            return {};
        
        vector<int> result;
        
        solve(result,root);
        
        return result;
    }
};