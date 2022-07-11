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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() == 0) return {};

        priority_queue<int, vector<int>, greater<int>> minhp;
        ListNode *head;
        for (int i = 0; i < lists.size(); i++){
            head = lists[i];

            while (head){
                minhp.push(head->val);
                head = head->next;
            }
        }
        if(minhp.size() == 0) return {};

        ListNode *res = new ListNode;
        head = res;
        while (!minhp.empty()){
            res->val = minhp.top();
            minhp.pop();

            if(!minhp.empty()){
                res->next = new ListNode;
                res = res->next;
            }

        }

        res->next = NULL;
        return head;
    }
};
