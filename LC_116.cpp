/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(!root) return root;
        
        queue<Node*> q;
        q.push(root);
        int size;
        Node *temp;
        
        while (!q.empty()){
            size = q.size();
            if(q.front() == NULL) break;
            
            for (int i = 0; i < size; i++){
                temp = q.front();
                q.pop();
                
                if(i != size - 1) temp->next = (q.front());
                
                q.push(temp->left);
                q.push(temp->right);
            
            }
            
            temp->next = NULL;
        }
        
        return root;
    }
};