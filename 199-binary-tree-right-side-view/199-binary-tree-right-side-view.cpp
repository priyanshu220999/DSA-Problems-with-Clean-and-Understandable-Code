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
    vector<int> rightSideView(TreeNode* root) {
        
        if(!root)
            return {};
        
        vector<int> result;
        
        queue<pair<TreeNode*,int>> hash;
        
        map<int,TreeNode*> nodes;
        
        hash.push({root,0});
        
        while(!hash.empty()){
            
            int n = hash.size();
            
            for(int i=0;i<n;i++){
                
                auto cur = hash.front();
                hash.pop();
                TreeNode* temp = cur.first;
                int x = cur.second;
                nodes[x] = temp;
                
                if(temp->left)
                    hash.push({temp->left,x+1});
                if(temp->right)
                    hash.push({temp->right,x+1});
            }
        }
        
        for(auto ptr:nodes){
            result.push_back(ptr.second->val);
        }
        
        return result;
    }
};