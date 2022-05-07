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
    bool isPalindrome(ListNode* head) {
        if (head->next == NULL) return true;

        if (head->next->next == NULL){
            if (head->val == head->next->val){
                return true;
            }else{
                return false;
            }
        }
        
        ListNode *slow = NULL, *fast = new ListNode, *slow_adv = head, *slow_lag;
        fast->next = head;
        
        
        while (fast != NULL && fast->next != NULL){
            fast = fast->next->next;
            slow_lag = slow;
            slow = slow_adv;
            slow_adv = slow_adv->next;
            
            slow->next = slow_lag;
            
        }
        
        if (fast == NULL ){
            slow = slow->next;
        }
        
        while (slow != NULL){
            if (slow_adv->val != slow->val){
                return false;
            }else{
                slow = slow->next;
                slow_adv = slow_adv->next;
            }
        }
        
        return true;
    }
};