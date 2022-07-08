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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        
        vector<vector<int>> result;
        
        if(!root)
            return result;
        
        map<int,map<int,multiset<int>>> nodes;
        queue<pair<TreeNode*,pair<int,int>>> todo;
        
        todo.push({root,{0,0}});
        
        while(!todo.empty()){
            
            auto cur = todo.front();
            
            todo.pop();
            
            TreeNode* temp = cur.first;
            
            int x = cur.second.first, y = cur.second.second;
            
            nodes[x][y].insert(temp->val);
            
            if(temp->left)
                todo.push({temp->left,{x-1,y+1}});
            if(temp->right)
                todo.push({temp->right,{x+1,y+1}});
        }
        
        for(auto i:nodes){
            vector<int> answer;
            for(auto j:i.second){
                answer.insert(answer.end(),j.second.begin(),j.second.end());
            }
            result.push_back(answer);
        }
        
        return result;
    }
};