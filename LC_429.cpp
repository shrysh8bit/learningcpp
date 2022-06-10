
class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> vals;
        vector<int> lvl;
        int size;
        queue<Node*> q;

        if (root == NULL) return vals;
        q.push(root);

        while (!q.empty()){
            size = q.size();
            lvl.clear();

            for(int i = 0; i < size; i++){
                auto curr = q.front();
                q.pop();
                lvl.push_back(curr->val);

                for(auto nodes: curr->children){
                    q.push(nodes);
                }

            }
            vals.push_back(lvl);

        }

        return vals;
    }
};
