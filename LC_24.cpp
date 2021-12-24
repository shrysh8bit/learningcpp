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
    ListNode* swapPairs(ListNode* head) {
        if( head == NULL || head->next == NULL) return head;
        
        ListNode* left = head, *right = head, *lag = head;
        
        head = head->next;
        
        while(right != NULL && right->next != NULL){
            // cout << left->val << "   " << right->val << endl;
            right = right->next;
            left->next = right->next;
            right->next = left;
            if(right != head){
                lag->next = right;
            }
            lag = left;
            left = left->next;
            right = left;
            
        }
        
        return head;
        
    }
};