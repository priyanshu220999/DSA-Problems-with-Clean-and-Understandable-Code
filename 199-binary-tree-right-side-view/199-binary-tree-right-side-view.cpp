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
    
    void help(TreeNode* root,int level,vector<int> &result){
        
        if(!root)
            return;
        
        if(level==result.size())
            result.push_back(root->val);
        help(root->right,level+1,result);
        help(root->left,level+1,result);
    }
    
public:
    vector<int> rightSideView(TreeNode* root) {
        
        if(!root)
            return {};
        
        vector<int> result;
        
        help(root,0,result);
        
        return result;
    }
};