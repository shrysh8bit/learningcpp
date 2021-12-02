        
//         for (auto pr : lo_inorder){
//             cout << "   lo inorder  " << pr ;
//         }
//         cout << endl;
        
//         for (auto pr : lo_postorder){
//             cout << "   lo postorder  " << pr ;
//         }
//         cout << endl;
        
//         for (auto pr : high_inorder){
//             cout << "   high inorder  " << pr ;
//         }
//         cout << endl;
        
//         for (auto pr : high_postorder){
//             cout << "   high postorder  " << pr ;
//         }
//         cout << endl;
        

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
    
    TreeNode* root =new TreeNode;
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) { 
        
        bst(root, inorder, postorder);
        return root;
    }
    
    TreeNode* bst(TreeNode* root, vector<int> inorder, vector<int> postorder){
        if (postorder.size() == 1){
            root->val = *postorder.begin();
            return root;
        }  
        
        root->val = *(postorder.end()-1);
        
        int count = 0;
        vector<int>::iterator it = inorder.begin();
        
        while (*it != root->val){
            count++;
            it++;
        }
        
        vector<int> lo_inorder(inorder.begin(), inorder.begin() + count);
        vector<int> lo_postorder(postorder.begin(), postorder.begin() + count);
        
        vector<int> high_inorder(inorder.begin()+ count + 1, inorder.end());
        vector<int> high_postorder(postorder.begin() + count, postorder.end() -1 );

        if(lo_inorder.size() != 0){
            root->left = new TreeNode;
            bst(root->left, lo_inorder, lo_postorder);
        }
        
        if(high_inorder.size() != 0){
            root->right = new TreeNode;
            bst(root->right, high_inorder, high_postorder);
        }
        
        return root;
    }
};