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
    ListNode* reverseList(ListNode* head) {
        if(!head || head->next == NULL) return head;
        
        ListNode* lag = head, *middle, *lead = head->next;
        head->next = NULL;
    
        while(lead != NULL){
            middle = lead;
            lead = lead->next;
            middle->next = lag;
            lag = middle;
        }
        
        return middle;
    }
};