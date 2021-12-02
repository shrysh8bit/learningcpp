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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        if ( head == NULL){
            return NULL;
        }
        
        TreeNode* root = new TreeNode;
        root = bst(head, root);
        return root;
    }
    
    TreeNode* bst(ListNode* head, TreeNode* root){
        if ( head->next == NULL){
            root->val = head->val;
            return root;
        }
        
        ListNode *previous = head, *slow = head, *fast = head;
        
        while (fast->next != NULL){
            previous = slow;
            slow = slow->next;
            fast = fast->next;
            if(fast->next != NULL){
                fast = fast->next;
            }
        }
        
        root->val = slow->val;
        previous->next = NULL;
               
        root->left = new TreeNode;
        bst(head, root->left);
        
        if(slow->next != NULL){
            slow = slow->next;
            root->right = new TreeNode;
            bst(slow, root->right);
        
        }
        
        return root;
        
    }
};