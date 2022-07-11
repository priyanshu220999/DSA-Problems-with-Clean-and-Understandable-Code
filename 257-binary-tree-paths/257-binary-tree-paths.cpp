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
    
    bool isLeafNode(TreeNode* root){
        return (!root->left && !root->right);
    }
    
    void help(TreeNode* root,string path,vector<string> &paths){
        
        if(!root->left && !root->right){
            paths.push_back(path);
            return;
        }
        
        if(root->left)
            help(root->left,path+"->"+to_string(root->left->val),paths);
        if(root->right)
            help(root->right,path+"->"+to_string(root->right->val),paths);
    }
    
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        
        vector<string> paths;
        
        if(!root)
            return paths;
        if(isLeafNode(root)){
            paths.push_back(to_string(root->val));
            return paths;
        }
        
        help(root,to_string(root->val),paths);
        
        return paths;
    }
};