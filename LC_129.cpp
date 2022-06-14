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
    int sum = 0, level = -1;
    TreeNode* curr_node;
    stack<TreeNode*> stk;
    vector<int> curr_sum;


    int sumNumbers(TreeNode* root) {

        stk.push(root);
        level++;

        curr_sum.push_back(root->val);

        if(root->left != NULL) sumNumbers(root->left);
        if(root->right != NULL) sumNumbers(root->right);
        stk.pop();

        if(root->left == NULL && root->right == NULL){
            sum += findSum();
        }

        curr_sum.pop_back();
        level--;

        return sum;
    }

    int findSum (){
        int sum = 0, level = 0;

        for (auto it = curr_sum.rbegin(); it != curr_sum.rend(); it++){
            sum += (*it)*(pow(10, level));
            level++;
        }
        // cout << sum << endl;
        return sum;
    }
};
