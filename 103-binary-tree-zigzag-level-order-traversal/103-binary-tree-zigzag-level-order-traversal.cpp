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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        
        vector<vector<int>> result;
        
        if(!root)
            return result;
        
        queue<TreeNode*> hash;
        hash.push(root);
        int dir = 0;
        
        while(!hash.empty()){
            
            int n = hash.size();
            vector<int> curLevel(n);
            
            for(int i=0;i<n;i++){
                
                TreeNode* temp = hash.front();
                hash.pop();
                
                int index = dir==0?i:n-1-i;
                
                curLevel[index] = temp->val;
                
                if(temp->left)
                    hash.push(temp->left);
                if(temp->right)
                    hash.push(temp->right);
            }
            result.push_back(curLevel);
            dir = (dir+1)%2;
        }
        return result;
    }
};