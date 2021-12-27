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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if ( head->next == NULL) return head;
        if ( left == right ) return head;
        
        int temp = left;
        
        ListNode* l = head, *r = head, *index_l = l, *middle = head, *index_r;
        
        for ( int i = 1; i < right; i++){
            r = r->next;
            
            if (left > 1){
                index_l = l;
                l = l->next;
                left--;
            }
        }        
        
        if(temp != 1){
            index_l->next = r;
        }
        index_l = l;
        index_r = r->next;
        r->next = NULL;
        r = l;
        
        middle = l->next;
        
        while ( r != NULL){
            if (middle != NULL){
                r = middle->next;
            }
            middle->next = l;
            l = middle;
            middle = r;
        }
        
        index_l->next = index_r;
        if ( temp == 1) head = l;
        return head;
    }
};