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
    int numComponents(ListNode* head, vector<int>& nums) {
        map<int, int> source;
        int ans = 0;
        
        for ( auto pr : nums){
            source[pr] = 1;
        }
        
        while ( head != NULL && head->next != NULL){
            if( source[head->val] == 1 && source[head->next->val] != 1){
                ans++;
            
            }
            
            head = head->next;
        }
        
        if(head->next == NULL && source[head->val] == 1)ans++;
        
        return ans;
    }
};