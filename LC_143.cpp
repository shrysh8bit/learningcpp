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
    void reorderList(ListNode* head) {
        vector<ListNode* > ptrs;
        ListNode* ptr = head;
        int i = 0;
        
        while (ptr != NULL){
            ptrs.push_back(ptr);
            ptr = ptr->next;
        }
        
        ListNode* temp = new ListNode(5);
        
        int left = 0, rt = ptrs.size() -1;
        for ( int i = 0; i < ptrs.size() ; i++){
            if (i % 2 == 1 ){
                temp->next = ptrs[rt];
                rt--;
            }else{               
                temp->next = ptrs[left];
                left++;
            }
            temp = temp->next;
        }
        temp->next = NULL;
        
        
    }
};