class Solution {
public:
    vector<int> traversal;

    vector<int> preorder(Node* root) {
        travel(root);
        return traversal;
    }

    void travel (Node* root){
        if (!root) return;

        traversal.push_back(root->val);

        // for ( int i = 0; i < root->children.size(); i++){
        for ( auto node : root->children){
            travel(node);
        }
    }

};
