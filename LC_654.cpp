#include<iostream>
#include<vector>

using namespace std;

struct TreeNode{
	int val;
	TreeNode* left;
	TreeNode* right;
};

TreeNode* bst(TreeNode* root, vector<int>& nums){

	// root = new TreeNode;

	if(nums.size() == 1){
		root->val = *nums.begin();
		return root;
	}

	int max = 0,index;

	for ( int  i = 0; i < nums.size(); i++){
		if (nums[i] > max) {
			max = nums[i];
			index = i;
		}
	}

	std::vector<int> lo(nums.begin(),nums.begin() + index), hi(nums.begin() + index + 1, nums.end());


	// for ( auto pr : lo){
	// 	cout << pr << " " ;
	// }
	// cout << "    hi: ";
	
	// for ( auto pr : hi){
	// 	cout << pr << " " ;
	// }
	// cout << endl;
	

	if (lo.size() > 0) {
		root->left = new TreeNode;
		bst(root->left, lo);
	}
	
	if (hi.size() > 0){
		root->right = new TreeNode;
		bst(root->right, hi);
	} 

	return root;
}

TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
	TreeNode* root;
	root = new TreeNode;
	root = bst(root, nums);

	return root;
}


int main(){
	vector<int> nums = {3,2,1,6,0,5,8};

	TreeNode* root;
	root = constructMaximumBinaryTree(nums);

	return 0 ;
}