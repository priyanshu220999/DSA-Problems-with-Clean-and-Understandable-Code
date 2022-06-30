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
    
    int findHeight(TreeNode* root){
        
        if(!root)
            return 0;
        
        return 1 + max(findHeight(root->left),findHeight(root->right));
    }
    
public:
    bool isBalanced(TreeNode* root) {
        
        if(!root)
            return true;
        
        int lh = findHeight(root->left);
        int rh = findHeight(root->right);
        
        if(abs(lh-rh)>1)
            return false;
        
        bool lCheck = isBalanced(root->left);
        bool rCheck = isBalanced(root->right);
        
        if(!lCheck || !rCheck) 
            return false;
        
        return true;
    }
};