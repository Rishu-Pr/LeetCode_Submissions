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
    void getPreOrder(vector<int> &V,TreeNode *root){
        V.push_back(root->val);
        if(root->left) getPreOrder(V,root->left);
        if(root->right) getPreOrder(V,root->right);
    }
public:
    int findSecondMinimumValue(TreeNode* root) {
        vector<int> V;
        getPreOrder(V,root);
        sort(V.begin(),V.end());
        for(int i = 1; i < V.size(); i++){
            if(V[i] != V[0]) return V[i];
        }
        return -1;
    }
};