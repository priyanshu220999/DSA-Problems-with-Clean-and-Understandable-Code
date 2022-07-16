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
    
    TreeNode* buildTree(vector<int> &inorder,int inStart,int inEnd,vector<int> &postorder,int postStart,int postEnd,map<int,int> &hash){
        
        if(inStart>inEnd || postStart>postEnd)
            return nullptr;
        
        TreeNode *root = new TreeNode(postorder[postEnd]);
        
        int inRootIndex = hash[root->val];
        
        int numsLeft = inRootIndex-inStart;
        
        root->left = buildTree(inorder,inStart,inRootIndex-1,postorder,postStart,postStart+numsLeft-1,hash);
        root->right = buildTree(inorder,inRootIndex+1,inEnd,postorder,postStart+numsLeft,postEnd-1,hash);
        
        return root;
    }
    
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        
        int n = inorder.size();
        
        map<int,int> hash;
        
        for(int i=0;i<n;i++)
            hash[inorder[i]] = i;
        
        TreeNode *root = buildTree(inorder,0,n-1,postorder,0,n-1,hash);
        
        return root;
    }
};