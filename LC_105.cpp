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
    TreeNode* root;
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
        if (preorder.size() == 1){
            root = new TreeNode;
            root->val = *preorder.begin();
            return root;
        }
        
        root = new TreeNode;
        bst(root, preorder, inorder);
       
        return root;
        
        
    }
    
    TreeNode* bst (TreeNode* root, vector<int>& preorder, vector<int>& inorder){
        // root = new TreeNode;
        root->val = *preorder.begin();
        
        int count = 0;
        vector<int>::iterator it = inorder.begin();
        while (*it != root->val){
            count++;
            it++;
        }
        
        
        
        vector<int> lo_preorder(preorder.begin() + 1, preorder.begin() + count + 1);
        vector<int> lo_inorder(inorder.begin(), inorder.begin() + count);
        
        vector<int> high_preorder(preorder.begin() + count + 1, preorder.end());
        vector<int> high_inorder(inorder.begin() + count+1, inorder.end());

        
        if (lo_preorder.size() != 0){
            
            root->left = new TreeNode;   
            if (lo_preorder.size() == 1){
                (root->left)->val = *lo_preorder.begin();
            }else{
                bst(root->left,lo_preorder, lo_inorder);
            }
        }
        
        if (high_preorder.size() != 0){
            
            root->right = new TreeNode;

            if (high_preorder.size() == 1){
                (root->right)->val = *high_preorder.begin();
            }else{
                bst(root->right, high_preorder, high_inorder);
            }
        }
        
        return root;
    }
};