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
    bool isCompleteTree(TreeNode* root) {
        
        if(!root)
            return true;
        
        queue<TreeNode*> hash;
        hash.push(root);
        TreeNode* x = nullptr;
        bool nullNode = false;
        
        while(!hash.empty()){
            
            TreeNode* temp = hash.front();
            hash.pop();
            
            if(temp==nullptr){
                nullNode = true;
            }
            else{
                
                if(nullNode)
                    return false;
                
                if(temp->left) hash.push(temp->left);
                else hash.push(x);
                if(temp->right) hash.push(temp->right);
                else hash.push(x);
            }
        }
        return true;
    }
};