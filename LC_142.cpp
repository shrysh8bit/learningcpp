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
        map<ListNode*, int> map_addr;
        ListNode* ptr = head;
        if ( ptr == NULL) return NULL;
        
        while(ptr->next != NULL){
            if ( map_addr[ptr] == 1) return ptr;
            map_addr[ptr] = 1;
            ptr = ptr->next;
        }
        
        return NULL;
    }
};