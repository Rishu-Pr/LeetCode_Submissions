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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> V;
        if(root == NULL) return V;

        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            vector<int> V_temp;

            for(int i = 0; i < size; i++){
                TreeNode *temp = q.front();
                q.pop();

                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
                V_temp.push_back(temp->val);
            }
            V.push_back(V_temp);
        }

        for(int i = 1; i < V.size(); i+=2)
            reverse(V[i].begin(),V[i].end());
        

        return V;
    }
};