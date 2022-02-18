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
    
    bool is_even(int n){
        return n%2==0;
    }
    
public:
    ListNode* oddEvenList(ListNode* head) {
        
        if(head==nullptr || head->next==NULL || head->next->next==NULL){
            return head;
        }
        
        ListNode *last = head;
        
        int size = 1;
        
        while(last->next){
            last = last->next;
            size++;
        }
        ListNode *ptr = head,*ptr_prev = nullptr;
        int i = 1;
        while(ptr->next && i<=size){
            
            if(is_even(i)){
                ptr_prev->next = ptr->next;
                ptr->next = NULL;
                last->next = ptr;
                last = last->next;
                ptr = ptr_prev->next;
            }
            else{
                ptr_prev = ptr;
                ptr = ptr->next;
            }
            i++;
        }
        return head;
    }
};