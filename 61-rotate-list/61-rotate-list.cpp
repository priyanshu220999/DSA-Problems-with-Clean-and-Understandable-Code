/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        
        if(k==0)
            return head;
        if(head==nullptr || head->next==NULL)
            return head;
        
        int size = 0;
        
        ListNode *s = head;
        while(s){
            s = s->next;
            size++;
        }
        
        k = k%size;
        if(k==0)
            return head;
        int i = 0;
        
        while(i<k){
            ListNode *q,*p = head;
            
            while(p->next){
                q = p;
                p = p->next;
            }
            p->next = head;
            q->next = NULL;
            head = p;
            i++;
        }
        return head;
    }
};