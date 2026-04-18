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
    void swapping(TreeNode* root){
        if(!root) return;
        swapping(root->left); 
        swapping(root->right);

        TreeNode* temp = root->left;
        root->left = root->right;
        root->right = temp;
    }
public:
    TreeNode* invertTree(TreeNode* root) {
        swapping(root);
        return root;
    }
};