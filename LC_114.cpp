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
    void flatten(TreeNode* root) {
        queue<TreeNode*> addr;
        ptr_seq(root, addr);
        
        TreeNode* temp = new TreeNode();
        while(!addr.empty()){
            temp->left = NULL;
            temp->right = addr.front();
            addr.pop();
            temp = temp->right;
        }
    }
    
    void ptr_seq(TreeNode* root, queue<TreeNode*>& addr){
        if (!root) return;
        
        addr.push(root);
        
        ptr_seq(root->left, addr);
        ptr_seq(root->right, addr);
    }
};