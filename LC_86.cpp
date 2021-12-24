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
    ListNode* partition(ListNode* head, int x) {
        if(head == NULL || head->next == NULL) return head;
        
        ListNode* plower = NULL, *phigher = NULL, *low, *high;
        bool init_s = 0, init_l = 0;
        
        while (head != NULL){
            
            if ( head->val >= x){
                if(init_l == false){
                    phigher = new ListNode(head->val);
                    init_l = 1;
                    high = phigher;
                }else{
                    high->next = new ListNode(head->val);
                    high = high->next;
                }
                
            }else{
                if(init_s == false){
                    plower = new ListNode(head->val);
                    init_s = 1;
                    low = plower;
                }else{
                    low->next = new ListNode(head->val);
                    low = low->next;
                }
            }
            
            head = head->next;
        }
        if(phigher == NULL) return plower;
        if(plower == NULL) return phigher;
        
        low->next = phigher;
        return plower;
        
        
        
    }
};