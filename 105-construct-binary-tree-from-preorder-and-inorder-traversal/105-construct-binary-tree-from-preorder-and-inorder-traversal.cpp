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
    
    TreeNode *buildTree(vector<int> &preorder,int preStart,int preEnd,vector<int> &inorder,int inStart,int inEnd,map<int,int> &hash){
        
        if(inStart>inEnd || preStart>preEnd)
            return nullptr;
        
        TreeNode *root = new TreeNode(preorder[preStart]);
        
        int inRootIndex = hash[root->val];
        
        int numsLeft = inRootIndex-inStart;
        
        root->left = buildTree(preorder,preStart+1,preStart+numsLeft,inorder,inStart,inRootIndex-1,hash);
        root->right = buildTree(preorder,preStart+numsLeft+1,preEnd,inorder,inRootIndex+1,inEnd,hash);
        
        return root;
    }
    
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
        int n = preorder.size();
        
        map<int,int> hash;
        
        for(int i=0;i<n;i++){
            hash[inorder[i]] = i;
        }
        
        TreeNode* root = buildTree(preorder,0,n-1,inorder,0,n-1,hash);
        
        return root;
    }
};