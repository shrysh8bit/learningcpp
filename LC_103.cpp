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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        int even = 0, count;
        queue<TreeNode* > q;
        vector<vector<int>> result;
        vector<int> row;
        TreeNode* curr;

        if (root == NULL) return result;

        q.push(root);

        while (!q.empty()){
            count = q.size();
            row.clear();

            for (int i = 0; i < count; i++){
                curr = q.front();
                q.pop();

                row.push_back(curr->val);

                if(curr->left != NULL) q.push(curr->left);
                if(curr->right != NULL) q.push(curr->right);
            }

            even = even % 2;
            if (even) {
                reverse(row.begin(), row.end());
            }

            even++;

            result.push_back(row);
        }

        return result;
    }
};
