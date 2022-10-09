class Solution {
public:
    bool isValidBST(TreeNode* root) {
        double lmin = pow(INT_MIN,3), lmax =  pow(2, 33), value = root->val;
        return bst(root->left, value, lmin) && bst (root->right, lmax, value);
    }

    bool bst(TreeNode *root, double last_left,double last_right){
        if(!root) return true;

        if(root->val >= last_left || root->val <=last_right ) {
            bool r1 = root->val >= last_left;
            bool r2 = root->val <=last_right;
            return false;

        }

        return bst(root->left, root->val, last_right) && bst(root->right, last_left, root->val);

    }
};
