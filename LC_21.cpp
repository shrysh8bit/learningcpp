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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* newLL = NULL, *temp;
        
        if ( list1 == NULL && list2 == NULL) return NULL;
        
        while ( list1 != NULL || list2 != NULL){
            if ( newLL == NULL){
                newLL = new ListNode;
                temp = newLL;
            }else{
                newLL->next = new ListNode;
                newLL = newLL->next;
            }
            
            if(list1 == NULL && list2 != NULL){
                newLL->val = list2->val;
                if ( list2->next == NULL){
                        list2 = NULL;
                    }else{
                        list2 = list2->next;
                    }
            }
            
            if (list1 != NULL && list2 == NULL){
                newLL->val = list1->val;
                if ( list1->next == NULL){
                        list1 = NULL;
                    }else{
                        list1 = list1->next;
                    }
            }
            
            
            if(list1 != NULL && list2 != NULL){
                if(list2->val >= list1->val){
                    newLL->val = list1->val;
                    if ( list1->next == NULL){
                        list1 = NULL;
                    }else{
                        list1 = list1->next;
                    }
                }else{
                    newLL->val = list2->val;
                    if ( list2->next == NULL){
                        list2 = NULL;
                    }else{
                        list2 = list2->next;
                    }
                }
            }
            
            
            
        }            
    
    return temp;
    
    }
};