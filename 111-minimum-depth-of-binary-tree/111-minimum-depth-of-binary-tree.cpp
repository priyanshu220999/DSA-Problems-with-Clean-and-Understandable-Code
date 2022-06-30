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
    int minDepth(TreeNode* root) {
        
        if(root == nullptr)
            return 0;
        
        queue<TreeNode*> hash;
        hash.push(root);
        int i = 0;
        
        while(!hash.empty()){
            
            i++;
            int n = hash.size();
            
            for(int j=0;j<n;j++){
                
                TreeNode* temp = hash.front();
                
                hash.pop();
                
                if(temp->left) hash.push(temp->left);
                if(temp->right) hash.push(temp->right);
                
                if(temp->left == NULL && temp->right == NULL)
                    return i;
            }
        }
        return -1; //Juts for the compiler...
    }
};