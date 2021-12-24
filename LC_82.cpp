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
    ListNode* deleteDuplicates(ListNode* head) {
        if ( head == NULL || head->next == NULL) return head;
        
        ListNode* ptr = head, *lag = head;
        int temp;
        
        while( (ptr != NULL) && (ptr->next) != NULL){
            
            if(ptr->val == ptr->next->val){

                temp = ptr->val;
                
                while(ptr != NULL && ptr->val == temp){
                    ptr = ptr->next;
                }

                if(lag == head && lag->val == temp){
                    head = ptr;
                    lag = head;
                }else{
                    lag->next = ptr; 
                }
                
            }else{
                lag = ptr;
                ptr = ptr->next;
            }
            
            
        }
        
        return head;
    }
};