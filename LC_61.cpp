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
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == NULL){
            return head;
        }
        ListNode* lag = head,*end =head;
        int size = 0;
            
        while (end->next != NULL){
            end = end->next;
            size++;
        }
        size++;
        
        k = k % size;
        
        for (int i = 1; i < (size - k) ; i ++){
            lag = lag->next;
        }
        end->next = head;
        head = lag->next;
        lag->next = NULL;

        return head;
    }
};