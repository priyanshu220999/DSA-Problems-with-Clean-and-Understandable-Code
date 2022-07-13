/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    
    void parentMap(TreeNode* root,unordered_map<TreeNode*,TreeNode*> &childParent){
        
        queue<TreeNode*> hash;
        hash.push(root);
        
        while(!hash.empty()){
            
            int n = hash.size();
            
            for(int i=0;i<n;i++){
                
                TreeNode* temp = hash.front();
                hash.pop();
                
                if(temp->left){
                    hash.push(temp->left);
                    childParent[temp->left] = temp;
                }
                if(temp->right){
                    hash.push(temp->right);
                    childParent[temp->right] = temp;
                }
            }
        }
    }
    
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        
        vector<int> result;
        unordered_map<TreeNode*,TreeNode*> parent;
        parentMap(root,parent);
        
        queue<TreeNode*> hash;
        hash.push(target);
        unordered_map<TreeNode*,bool> visited;
        visited[target] = true;
        int gap = 0;
        
        while(!hash.empty()){
            
            int n = hash.size();
            if(gap++ == k) break;
            
            for(int i=0;i<n;i++){
                
                TreeNode *temp = hash.front();
                hash.pop();
                
                if(temp->left && !visited[temp->left]){
                    hash.push(temp->left);
                    visited[temp->left] = true;
                }
                if(temp->right && !visited[temp->right]){
                    hash.push(temp->right);
                    visited[temp->right] = true;
                }
                if(parent[temp] && !visited[parent[temp]]){
                    hash.push(parent[temp]);
                    visited[parent[temp]] = true;
                }
            }
        }
        while(!hash.empty()){
            TreeNode * temp = hash.front();
            hash.pop();
            result.push_back(temp->val);
        }
        return result;
    }
};