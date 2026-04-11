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
    void preorder(TreeNode* root,vector<int> &V){
        if(root == NULL)
            return;
        
        V.push_back(root->val);
        preorder(root->left,V);
        preorder(root->right,V);
    }
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> V;
        preorder(root,V);

        return V;
    }
};