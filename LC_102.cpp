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
    
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        vector<int> temp;
        stack<TreeNode*> stk1, stk2;
        if (root == NULL) return ans;
        
        stk1.push(root);
        level (ans, temp, stk1, stk2);
        
        return ans;
    }
    
    
    void level(vector<vector<int>>& ans, vector<int>& temp, stack<TreeNode*>& stk1, stack<TreeNode*>& stk2){
        
        while( !(stk1.empty()) ){            
            temp.push_back((stk1.top())->val);
            
            if ( (stk1.top())->left != NULL){
                stk2.push(stk1.top()->left);
            }
            
            if(  (stk1.top())->right != NULL ){
                stk2.push(stk1.top()->right);
            }
            
            stk1.pop();
        }
        
        ans.push_back(temp);
        temp.clear();
        
        while(!stk2.empty()){
            stk1.push(stk2.top());
            stk2.pop();
        }
        
        if ( !stk1.empty() ){
            level(ans, temp, stk1, stk2);
        }
        
        return;
        
    }
};