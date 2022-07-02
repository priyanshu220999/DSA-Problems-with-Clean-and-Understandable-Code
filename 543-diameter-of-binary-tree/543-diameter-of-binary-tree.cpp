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
    
    int diameter = 0;
    
    int findHeight(TreeNode* root){
        if(!root)
            return 0;
        return 1 + max(findHeight(root->left),findHeight(root->right));
    }
    
public:
    int diameterOfBinaryTree(TreeNode* root) {
        
        if(!root)
            return 0;
        
        int lh = findHeight(root->left);
        int rh = findHeight(root->right);
        
        diameter = max(diameter,lh+rh);
        
        diameterOfBinaryTree(root->left);
        diameterOfBinaryTree(root->right);
        
        return diameter;
    }
};