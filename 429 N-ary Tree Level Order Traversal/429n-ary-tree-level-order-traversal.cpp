/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> V;
        if(!root) return V;

        queue<Node*> q;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            vector<int> tempVal;
            for(int i = 0;i < size; i++){
                Node* temp = q.front();
                q.pop();
                tempVal.push_back(temp->val);
                for(Node* x: temp->children)
                    q.push(x);
            }
            V.push_back(tempVal);
        }

        return V;
    }
};