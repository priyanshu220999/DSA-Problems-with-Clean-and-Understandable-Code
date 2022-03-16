// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// design the class in the most optimal way

class LRUCache
{
    public:
    
    class node{
        public:
            int key;
            int val;
            node *next;
            node *prev;
            
            node(int key_,int val_){
                key = key_;
                val = val_;
            }
    };
    
    node *head = new node(-1,-1);
    node *tail = new node(-1,-1);
    
    int limit;
    unordered_map<int,node*> hash;
    
    void add_node(node *cur_node){
        
        node *temp = head->next;
        cur_node->next = temp;
        cur_node->prev = head;
        head->next = cur_node;
        temp->prev = cur_node;
    }
    
    void delete_node(node *del_node){
        
        node *del_prev = del_node->prev;
        node *del_next = del_node->next;
        del_prev->next = del_next;
        del_next->prev = del_prev;
    }
    
    //Constructor for initializing the cache capacity with the given value.
    LRUCache(int cap)
    {
        // code here
        limit = cap;
        head->next = tail;
        tail->prev = head;
    }
    
    //Function to return value corresponding to the key.
    int get(int key_)
    {
        // your code here
        if(hash.find(key_)!=hash.end()){
            
            node *cur_node = hash[key_];
            int result = cur_node->val;
            hash.erase(key_);
            delete_node(cur_node);
            add_node(cur_node);
            hash[key_] = head->next;
            return result;
        }
        return -1;
    }
    
    //Function for storing key-value pair.
    void set(int key_, int value)
    {
        // your code here
        if(hash.find(key_)!=hash.end()){
            node* cur_node = hash[key_];
            hash.erase(key_);
            delete_node(cur_node);
        }
        else if(hash.size()==limit){
            hash.erase(tail->prev->key);
            delete_node(tail->prev);
        }
        add_node(new node(key_,value));
        hash[key_] = head->next;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        int capacity;
        cin >> capacity;
        LRUCache *cache = new LRUCache(capacity);
        
        int queries;
        cin >> queries;
        while (queries--)
        {
            string q;
            cin >> q;
            if (q == "SET")
            {
                int key;
                cin >> key;
                int value;
                cin >> value;
                cache->set(key, value);
            }
            else
            {
                int key;
                cin >> key;
                cout << cache->get(key) << " ";
            }
        }
        cout << endl;
    }
    return 0;
}
  // } Driver Code Ends