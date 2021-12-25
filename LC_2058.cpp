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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        if(head->next->next == NULL || head->next->next->next == NULL) return {-1,-1};
        
        vector<int> dist;
        int count = 1;
        
        ListNode *prev = head, *present = head->next, *future = head->next->next;
        
        while (future != NULL){
            if(prev->val < present->val && present->val > future->val){
                dist.push_back(count);
            }else if(prev->val > present->val && present->val < future->val){
                dist.push_back(count);
            }
            
            prev = present;
            present = future;
            future = future->next;
            count++;
        }
        
        // for (auto pr : dist){
        //     cout << pr << " ";
        // }cout << endl;
        
        if(dist.size() == 0) return {-1, -1};
        if(dist.size() == 1) return {-1, -1};
        
        int min_dist = 200000, max_dist;
        
        for (int i = 0; i < dist.size() -1 ; i++){
            min_dist = min(min_dist, dist[i + 1] - dist[i]);
        }
        max_dist = dist.back() - dist.front();
        
        return {min_dist, max_dist};
        
    }
};