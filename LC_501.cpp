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
    
    vector<int> mode;
    int arr[200000] = {0};

    
    vector<int> findMode(TreeNode* root) {
        vector<int> final;
        count(root);
        
                
//         for (auto it = mode.begin(); it != mode.end(); ++it)
//         cout << ' ' << *it;
        
//         for (int i = 0; i < 2000; i++){
//             cout<< arr[i]<< "   ";
            
//         }
               
//         cout << endl;
        
        int max = 0;
        
        for (int i = 0; i < 100000; i++){
            if (arr[i] == max){
                final.push_back(i);
            }
                
            if (arr[i] > max){
                max = arr[i];
                final.erase(final.begin(), final.end());
                final.push_back(i);
            }          
        }
            
        for (int i = 100001; i < 200000; i++){
            if (arr[i] == max){
                final.push_back(i-200000);
            }
            if (arr[i] > max){
                max = arr[i];
                final.erase(final.begin(), final.end());
                final.push_back(i - 200000);
                
            }
        }
        
        
        
        
        return final;
    }
    
    void count (TreeNode *root){
        cout << "return 1" << endl;
        
        if (root->left == NULL && root->right == NULL){
            // mode.push_back(root->val);
            if (root->val >= 0){
                arr[root->val] += 1;
            }else{
                root->val += 200000;
                arr[root->val] += 1;
            }
               
            return ;
        }
        
        cout << "return 2" << endl;
        
        if (root->left != NULL){
            count (root->left);
        }
        // mode.push_back(root->val);
        
        if (root->val >= 0){
                arr[root->val] += 1;
        }else{
            root->val += 200000;
            arr[root->val] += 1;
        }        
        
        cout << "return 3" << endl;
        
        if (root->right != NULL){
            count(root->right);
        }
        
        cout << "return 4" << endl;
    
        return ;
    }
};