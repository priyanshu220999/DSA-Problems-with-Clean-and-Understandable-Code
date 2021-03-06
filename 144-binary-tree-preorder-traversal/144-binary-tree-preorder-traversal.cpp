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
    vector<int> preorderTraversal(TreeNode* root) {
        
        if(!root)
            return {};
        
        vector<int> result;
        
        stack<TreeNode*> stk;
        
        stk.push(root);
        
        while(!stk.empty()){
            
            TreeNode *temp = stk.top();
            
            stk.pop();
            
            result.push_back(temp->val);
            
            if(temp->right)
                stk.push(temp->right);
            if(temp->left)
                stk.push(temp->left);
        }
        
        return result;        
    }
};







