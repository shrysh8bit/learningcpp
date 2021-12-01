class Solution {
public:
    int nodes = 0; 
    int countNodes(TreeNode* root) {
        if ( root == NULL){
            return 0;
        }
        
        nodes++;
        
        if (root->left != NULL){
            countNodes(root->left);
        }
        
        if(root->right != NULL){
            countNodes(root->right);
        } 
        
        return nodes;
    }
};