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
    
    
    bool isSameTree(TreeNode* p, TreeNode* q) {
        
        bool left_1 = true, right_2 = true;
        
        // cout << p << "    "   << q << endl;
        if ((p == NULL) && (q == NULL) ){
            return true;
        }
        
        if ((p == NULL && q!= NULL) || (p != NULL && q == NULL)){
            return false;
        }
            
        if (((p->left == NULL) && (q->left != NULL)) || ((p->left != NULL) && (q->left == NULL))){
            return false;            
        }
        
         if (((p->right == NULL) && (q->right != NULL)) || ((p->right != NULL) && (q->right == NULL))){
            return false;            
        }
        
        if(p->val != q->val){
            return false;
        }
        
        if ((p->left == NULL) && (q->left == NULL)){
            left_1 = true;
        }else{
            left_1 = isSameTree(p->left, q->left);
            cout << "in here   " << left_1 << endl;
        }
                
        if ((p->right == NULL) && (q->right == NULL)){
            right_2 = true;
        }else{
            right_2 = isSameTree(p->right, q->right);
        }   

        return (left_1 && right_2);
        
    }
};