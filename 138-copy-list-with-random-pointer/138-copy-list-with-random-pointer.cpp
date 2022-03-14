/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        
        if(!head)
            return nullptr;
        if(!head->next){
            Node *copied = new Node(head->val);
            if(head->random==head){
                copied->random = copied;
            }
            return copied;
        }
        
        Node *q = head,*p = head->next,*copy_head;
        while(q){
            
            Node *temp = new Node(q->val);
            temp->next = p;
            q->next = temp;
            q = p;
            p = p?p->next:nullptr;
        }
        p = head;
        
        while(p){
            p->next->random = p->random?p->random->next:NULL;
            p=p->next;
            p=p?p->next:nullptr;
        }
        
        q = head;
        copy_head = head->next;
        p = head->next->next;
        
        while(p){
            
            q->next->next = p->next;
            q->next = p;
            
            q = p;
            p=p->next;
            p=p?p->next:nullptr;
        }
        
        if(q->next) q->next = NULL;
        return copy_head;
    }
};