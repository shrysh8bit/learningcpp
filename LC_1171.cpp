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
    ListNode* removeZeroSumSublists(ListNode* head) {
        // cout << "new " << endl;
        int sum = 0, temp;
        ListNode* ptr = head, *lag;
        vector<int> nums;        
        
        while (ptr != NULL){
            nums.push_back(ptr->val);
            ptr = ptr->next;
        }
                
        for (int i = 0; i < nums.size() ; i++ ){
            sum = 0;
            for (int j = i; j < nums.size(); j++){
                if (nums[j] < 1001){
                    sum += nums[j];        
                }
                
                if (sum == 0){
                    temp = i;
                    for (temp; temp <= j; temp++){
                        nums[temp] = 1001;
                    }
                    break;
                }
                
            }
            
        }
        
        ptr = head;
        for (int pr : nums){
            if (pr < 1001){               
                ptr->val = pr;
                lag = ptr;
                ptr = ptr->next;
                // cout << pr << " " << ptr->val<< endl;
            }
        }
        if (ptr == head) return NULL;
        lag->next = NULL;
        
        return head;
    }
};