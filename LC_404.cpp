class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        queue<pair<TreeNode*, int>> q;
        int sum = 0, is_left;
        q.push({root,0});
        TreeNode *front;

        while(!q.empty()){
            front = q.front().first;
            is_left = q.front().second;

            if(is_left && front->left == NULL && front->right == NULL){
                sum += front->val;
            }else{
                if(front->left) q.push({front->left, 1});
                if(front->right) q.push({front->right, 0});
            }

            q.pop();
        }

        return sum;
    }
};
