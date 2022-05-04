/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *slow = head;
        
        ListNode *fast = head;
        
        
        while (head != NULL && fast->next != NULL && fast->next->next != NULL){
            fast= fast->next->next;
            slow = slow->next;
            
            if (fast == slow){
                ListNode *temp = head;
                
                while (temp != slow ){
                    temp = temp->next;
                    slow = slow->next;
                }
                return slow;
            }
        }
        
        return NULL;
    }
};
