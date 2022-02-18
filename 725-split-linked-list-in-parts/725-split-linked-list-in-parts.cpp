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
    
    vector<int> find_quo_rem(ListNode* head,int k){
        
        int count = 0;
        
        vector<int> result;
        
        ListNode *p = head;
        
        while(p){
            count++;
            p=p->next;
        }
        
        if(count<=k)
            return {-1};
        int m = count%k;
        int q = count/k;
        
        return {q,m};
    }
    
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        
        vector<ListNode*> result;
        
        vector<int> quo_rem = find_quo_rem(head,k);
        
        ListNode *p = head,*q = nullptr;
        if(quo_rem[0]==-1){
            
            int i = 0;
            while(p && i<k){
                
                result.push_back(new ListNode(p->val));
                p = p->next;
                i++;
            }
            while(i<k){
                result.push_back(q);
                i++;
            }
            
        }
        else{
            int i = 0,j=0;
            while(p && i<k){
                
                if(j<quo_rem[1]){
                    int limit = quo_rem[0]+1;
                    while(p && limit>0){
                        q = p;
                        p = p->next;
                        limit--;
                    }
                    q->next = NULL;
                    result.push_back(head);
                    head = p;
                    q = nullptr;
                    j++;
                }
                else{
                    int limit = quo_rem[0];
                    while(p && limit>0){
                        q = p;
                        p = p->next;
                        limit--;
                    }
                    q->next = NULL;
                    result.push_back(head);
                    head = p;
                    q = nullptr;
                }
            }
        }
        return result;
    }
};