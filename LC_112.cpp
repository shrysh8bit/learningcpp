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
    int sum = 1001;
    
    bool hasPathSum(TreeNode* root, int targetSum) {
        if ( sum == 1001) sum = 0;
        
        if(!root) return 0;
        
        sum += root->val;
        // cout << sum << " " << root->val << endl;
        
        if ( !(root->left) && !(root->right)) {
            if(sum == targetSum){
                sum -= root->val;
                return true;
            }else{
                sum -= root->val;

                return false;
            }
        }
        bool temp;

        temp = temp || hasPathSum(root->left, targetSum);
        
        temp = temp || hasPathSum(root->right, targetSum);
        sum -= root->val;
        
        return temp;
    }
};