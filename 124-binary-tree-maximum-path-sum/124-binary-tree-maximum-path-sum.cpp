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
    
    int help(TreeNode* root,int &maxi){
        
        if(!root)
            return 0;
        
        int lSum = max(0,help(root->left,maxi));
        int rSum = max(0,help(root->right,maxi));
        
        maxi = max(maxi,lSum+rSum+root->val);
        
        return root->val+max(lSum,rSum);
    }
    
public:
    int maxPathSum(TreeNode* root) {
        
        if(!root)
            return 0;
        
        int result = INT_MIN;
        
        help(root,result);
        
        return result;
    }
};