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
    ListNode* deleteMiddle(ListNode* head) {
        ListNode* walker = head, *runner = head, *lag = head;
        
        if ( head->next == NULL) return NULL;
        
        while ( runner->next != NULL){
            runner = runner->next;
            if(runner->next != NULL){
                runner = runner->next;
            }
            lag = walker;
            walker = walker->next;
        }
        
        if (lag == head){
            head->next  = head->next->next;
            return head;
        }
        
        (lag->next) = (walker->next);
        return head;
        
        
    }
};