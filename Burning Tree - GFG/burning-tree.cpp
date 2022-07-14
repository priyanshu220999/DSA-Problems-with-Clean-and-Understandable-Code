// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};


Node *buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current Node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current Node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


 // } Driver Code Ends
//User function Template for C++

class Solution {
    
    Node* findNode(Node* root,int target){
        
        if(!root){
            return root;
        }
        
        if(root->data == target){
            return root;
        }
        
        Node *leftCheck = findNode(root->left,target);
        
        if(leftCheck && leftCheck->data == target){
            return leftCheck;
        }
        
        Node *rightCheck = findNode(root->right,target);
        
        return rightCheck;
    }
    
    void parentMarking(Node* root,unordered_map<Node*,Node*> &parent){
        
        queue<Node*> hash;
        hash.push(root);
        
        while(!hash.empty()){
            
            int n = hash.size();
            
            for(int i=0;i<n;i++){
                
                Node* temp = hash.front();
                hash.pop();
                
                if(temp->left){
                    hash.push(temp->left);
                    parent[temp->left] = temp;
                }
                if(temp->right){
                    hash.push(temp->right);
                    parent[temp->right] = temp;
                }
            }
        }
    }
    
  public:
    int minTime(Node* root, int target) 
    {
        // Your code goes here
        
        Node* targetNode = findNode(root,target);
        unordered_map<Node*,Node*> parent;
        parentMarking(root,parent);
        
        int result = 0;
        unordered_map<Node*,bool> visited;
        visited[targetNode] = true;
        queue<Node*> hash;
        hash.push(targetNode);
        
        while(!hash.empty()){
            
            int n = hash.size();
            result++;
            
            for(int i=0;i<n;i++){
                
                Node *temp = hash.front();
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
        return result-1;
    }
};

// { Driver Code Starts.

int main() 
{
    int tc;
    scanf("%d ", &tc);
    while (tc--) 
    {    
        string treeString;
        getline(cin, treeString);
        // cout<<treeString<<"\n";
        int target;
        cin>>target;
        // cout<<target<<"\n";

        Node *root = buildTree(treeString);
        Solution obj;
        cout<<obj.minTime(root, target)<<"\n"; 

        cin.ignore();

    }


    return 0;
}
  // } Driver Code Ends