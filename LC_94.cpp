#include <iostream>
#include <stack>
#include <utility>
#include <vector>

using namespace std;

struct TreeNode{
	TreeNode *left;
	int val;
	TreeNode *right;
};


void t_stack_insert(TreeNode* node, int data, stack<int> insert_direction){
	int direction;
	while(insert_direction.empty() == false){
		if (insert_direction.top() == 1){
			node = node->right;
		}
		else{
			node = node->left;
		}
		insert_direction.pop();
	}
	node = new TreeNode;
	node->val = data;
	node->left = NULL;
	node->right = NULL;
}


pair<TreeNode*, int> t_insert(TreeNode *node, int data, int count){
	count++;

	if(node == NULL){
		node = new TreeNode;
		node->left = NULL;
		node->right = NULL;
		return make_pair(node, count);
	}

	stack<int> insert_direction;
	int count_direction = count;

	while(count_direction != 1){
		if (count_direction%2 == 0){
			insert_direction.push(-1);
			// cout << count << " " << insert_direction.top() << endl;
		}
		else{
			insert_direction.push(1);
		}
		cout << count << " " << insert_direction.top() << endl;
		count_direction = count_direction/2;
	}

	t_stack_insert(node, data, insert_direction);

	return make_pair(node, count);
}

vector<int> t_print(TreeNode *head){

	

	if(head->left != NULL){
		t_print(head->left);
	}
	
	t_inorder.push_back(head->val);

	if(head->right != NULL){
		t_print(head->right);
	}

	return t_inorder;
}

int main (){
	TreeNode *root = NULL;
	int count = 0;
	pair<TreeNode*, int> pair_result;
	vector<int> t_inorder;

	pair_result = t_insert(root, 1, count);
	pair_result = t_insert(pair_result.first, 2, pair_result.second);
	pair_result = t_insert(pair_result.first, 3, pair_result.second);
	pair_result = t_insert(pair_result.first, 4, pair_result.second);
	pair_result = t_insert(pair_result.first, 5, pair_result.second);
	pair_result = t_insert(pair_result.first, 6, pair_result.second);
	pair_result = t_insert(pair_result.first, 7, pair_result.second);

	// t_inorder = t_print(pair_result.first);

	// for (auto it = t_inorder.begin(); it != t_inorder.end(); ++it)
 //        cout << ' ' << *it;

	// cout << pair_result.first << endl;
}