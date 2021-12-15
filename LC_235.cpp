/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root) return root;
        TreeNode* result;
        
        if (p->val == root->val  || q->val == root->val) return root;
        if (p->val > root->val   && q->val < root->val  || (p->val < root->val   && q->val > root->val) ) return root;
        if(p->val < root->val){
            result = lowestCommonAncestor(root->left, p, q);
        }else{
            result = lowestCommonAncestor(root->right, p, q);

        }
        
        return result;
    }
};