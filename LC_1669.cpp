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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* temp = list1, *orig;
        
        for ( int i = 0; i < a - 1; i++){
            temp = temp->next;
        }
        orig = temp;
        
        for ( int i = 0; i < b - a + 1; i++){
            orig = orig->next;
        }
        
        temp->next = list2;
        
        while(temp->next != NULL){
            temp = temp->next;
        }
        
        temp->next = orig->next;
        
        return list1;
    }
};