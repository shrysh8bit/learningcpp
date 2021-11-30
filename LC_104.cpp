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
    
    int depth_current = 0, depth = 0;
    
    int maxDepth(TreeNode* root) {
        
        if (root == NULL){
            return depth;
        }
        
        depth_current++;
        if (depth_current > depth) depth = depth_current;
        
        if (root->left != NULL){
            maxDepth(root->left);
        }
        
        if (root->right != NULL){
            maxDepth(root->right);    
        }else{
            depth_current--;
            return depth;
        }
        
        depth_current--;
        return depth;
    } 
        
        
    
};