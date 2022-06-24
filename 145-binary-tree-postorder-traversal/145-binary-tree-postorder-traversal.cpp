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
    
    void solve(vector<int> &result, TreeNode *root){
        
        if(!root)
            return;
        solve(result,root->left);
        solve(result,root->right);
        result.push_back(root->val);
    }
    
public:
    vector<int> postorderTraversal(TreeNode* root) {
        
        if(!root)
            return {};
        
        vector<int> result;
        
        solve(result,root);
        
        return result;
        
    }
};