// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// Tree Node
struct Node
{
    int data;
    Node* left;
    Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    
    return temp;
}

// Function to Build Tree
Node* buildTree(string str)
{   
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
            return NULL;
    
    // Creating vector of strings from input 
    // string after spliting by space
    vector<string> ip;
    
    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);
        
    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));
        
    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);
        
    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {
            
        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();
            
        // Get the current node's value from the string
        string currVal = ip[i];
            
        // If the left child is not null
        if(currVal != "N") {
                
            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->left);
        }
            
        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];
            
        // If the right child is not null
        if(currVal != "N") {
                
            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }
    
    return root;
}


 // } Driver Code Ends
/* A binary Tree node
struct Node
{
    int data;
    struct Node *left, *right;
};
*/

class Solution
{
private:

    Node* findNode(Node* root,int target){
        
        if(!root)
            return root;
        
        if(root->data == target){
            return root;
        }
        
        Node* left = findNode(root->left,target);
        
        if(left && left->data==target)
            return left;
        
        Node* right = findNode(root->right,target);
        
        return right;
    }
    
    void parentMap(Node* root,unordered_map<Node*,Node*> &hash){
        
        queue<Node*> level;
        
        level.push(root);
        
        while(!level.empty()){
            
            int n = level.size();
            
            for(int i=0;i<n;i++){
                
                Node* temp = level.front();
                level.pop();
                
                if(temp->left){
                    hash[temp->left] = temp;
                    level.push(temp->left);
                }
                if(temp->right){
                    hash[temp->right] = temp;
                    level.push(temp->right);
                }
            }
        }
    }
    
public:

    vector <int> KDistanceNodes(Node* root, int target , int k)
    {
        // return the sorted vector of all nodes at k dist
        
        Node* targetNode = findNode(root,target);
        unordered_map<Node*,Node*> parentTrack;
        parentMap(root,parentTrack);
        
        queue<Node*> hash;
        hash.push(targetNode);
        vector<int> result;
        unordered_map<Node*,bool> visited;
        visited[targetNode] = true;
        int gap = 0;
        
        while(!hash.empty()){
            
            int n = hash.size();
            
            if(gap++ == k) break;
            
            for(int i=0;i<n;i++){
                
                Node* temp = hash.front();
                hash.pop();
                
                if(temp->left && !visited[temp->left]){
                    hash.push(temp->left);
                    visited[temp->left] = true;
                }
                if(temp->right && !visited[temp->right]){
                    hash.push(temp->right);
                    visited[temp->right] = true;
                }
                if(parentTrack[temp] && !visited[parentTrack[temp]]){
                    hash.push(parentTrack[temp]);
                    visited[parentTrack[temp]] = true;
                }
            }
        }
        while(!hash.empty()){
            Node* temp = hash.front();
            hash.pop();
            result.push_back(temp->data);
        }
        sort(result.begin(),result.end());
        return result;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    getchar();
    
    Solution x = Solution();
    
    while(t--)
    {
        string s;
        getline(cin,s);
        Node* head = buildTree(s);
        
        int target, k;
        cin>> target >> k;
        getchar();
        
        vector <int> res = x.KDistanceNodes(head, target, k);
        
        for( int i=0; i<res.size(); i++ )
            cout<< res[i] << " ";
        cout<<endl;
    }
    return 0;
}
  // } Driver Code Ends