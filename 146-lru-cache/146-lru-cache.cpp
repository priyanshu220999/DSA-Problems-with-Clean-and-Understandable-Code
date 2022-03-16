class LRUCache {
public:
    
    class node{
        public:
            int key;
            int value;
            node* next;
            node* prev;
            node(int key_,int value_){
                key = key_;
                value = value_;
            }
    };
    
    node* head = new node(-1,-1);
    node* tail = new node(-1,-1);
    
    int cap;
    unordered_map<int,node*> hash;
    
    void add_node(node* cur_node){
        
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
    
    LRUCache(int capacity) {
        cap = capacity;
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key_) {
        
        if(hash.find(key_)!=hash.end()){
            
            node *cur_node = hash[key_];
            int result = cur_node->value;
            hash.erase(key_);
            delete_node(cur_node);
            add_node(cur_node);
            hash[key_] = head->next;
            return result;
        }
        return -1;
    }
    
    void put(int key_, int value) {
        
        if(hash.find(key_)!=hash.end()){
            
            node *cur_node = hash[key_];
            hash.erase(key_);
            delete_node(cur_node);
        }
        else if(hash.size()==cap){
            hash.erase(tail->prev->key);
            delete_node(tail->prev);
        }
        add_node(new node(key_,value));
        hash[key_] = head->next;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */