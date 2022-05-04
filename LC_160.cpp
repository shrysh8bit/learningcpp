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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        unordered_set<ListNode const*> node_map;
        
        while(headA != NULL || headB != NULL){
            
            if (headA != NULL){
                
                if (node_map.find(headA) != node_map.end()){
                    return headA;
                }else{
                    node_map.insert (headA);
                    headA = headA->next;
                }
            }
            
            if (headB != NULL){
                if (node_map.find(headB) != node_map.end()){
                    return headB;
                }else{
                    node_map.insert (headB);
                    headB = headB->next;
                }
            }
            
        }
        
        return NULL;
    }
};