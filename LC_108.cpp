#include<iostream>
#include<vector>

using namespace std;

struct TreeNode{
	int val;
	TreeNode* left;
	TreeNode* right;
};

TreeNode* bst(vector<int>& nums, TreeNode* head) {
	
	if (nums.size() == 0){
		return head;
	}

	head->val = nums[nums.size()/2 ];
	cout << head->val << endl;

	vector<int> lo(nums.begin(), nums.begin() + nums.size()/2);
	vector<int> high(nums.begin() + nums.size()/2 + 1, nums.end());


	for (auto pr : lo){
		cout << pr << endl;
	}

	for (auto pr : high){
		cout << pr << endl;
	}

	if(lo.size() != 0){
		bst (lo, head->left = new TreeNode);
	}
	
	if(high.size() != 0){
		bst (high, head->right = new TreeNode);
	}


	return head;
}



TreeNode* sortedArrayToBST(vector<int>& nums) {
    TreeNode *head = new TreeNode;

    if (nums.size() == 1){
    	head->val = *nums.begin();
        return NULL;
    }
	
    head = bst(nums, head);

    return head;
}
    




int main(){

	TreeNode* head = NULL;


	vector<int> nums;
	for(int i = 0; i< 1; i++){
		nums.push_back(i);
	}

	cout << nums.front() << endl;
	sortedArrayToBST(nums);
	// create_Tree(nums, head);
	// vector<int> mid = nums.size()/2;

	// vector<int> lo(nums.begin(), nums.begin() + nums.size()/2);
	// vector<int> high(nums.begin() + nums.size()/2 + 1, nums.end());

	// cout << nums[nums.size()/2] << endl;

	// for (auto pr : lo){
	// 	cout << pr << endl;
	// }

	// for (auto pr : high){
	// 	cout << pr << endl;
	// }


	return 0;
}




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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
         TreeNode *head = new TreeNode;

        if (nums.size() == 1){
            head->val = nums.front();
            return head;
        }

        head = bst(nums, head);

        return head;
    }
    
    
    TreeNode* bst(vector<int>& nums, TreeNode* head) {
	
        if (nums.size() == 0){
	    	return head;
        }

        head->val = nums[nums.size()/2 ];
        // cout << head->val << endl;

        vector<int> lo(nums.begin(), nums.begin() + nums.size()/2);
        vector<int> high(nums.begin() + nums.size()/2 + 1, nums.end());

        if(lo.size() != 0){
            bst (lo, head->left = new TreeNode);
        }

        if(high.size() != 0){
            bst (high, head->right = new TreeNode);
        }


        return head;    
    }

};
