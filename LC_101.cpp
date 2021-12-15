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
    bool isSymmetric(TreeNode* root) {
        return (same(root->left, root->right));
        
        
    }
    
    bool same(TreeNode* l_root, TreeNode* r_root){
        if(!l_root && !r_root) return true;
        if( (!l_root && r_root) || (l_root && !r_root) ) return false;
        
        bool result = true;
        
        result = result && same(l_root->left, r_root->right);
        result = result && same(l_root->right, r_root->left);
        
        if(l_root->val != r_root->val) return false;
        
        return result;
    }
};