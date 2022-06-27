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
    vector<int> postorderTraversal(TreeNode* root) {
        
        if(root==nullptr)
            return {};
        
        vector<int> result;
        
        stack<TreeNode*> hash;
        
        TreeNode* curr = root;
        
        while(curr!=NULL || !hash.empty()){
            
            if(curr){
                hash.push(curr);
                curr = curr->left;
            }
            else{
                TreeNode* temp = hash.top()->right;
                if(temp==NULL){
                    temp = hash.top();
                    hash.pop();
                    result.push_back(temp->val);
                    while(!hash.empty() && temp==hash.top()->right){
                        temp = hash.top();
                        hash.pop();
                        result.push_back(temp->val);
                    }
                }
                else{
                    curr = temp;
                }
            }
        }
        
        return result;
    }
};