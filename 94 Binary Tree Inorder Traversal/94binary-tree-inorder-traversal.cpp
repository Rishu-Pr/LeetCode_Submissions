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
    void inorder(TreeNode *root,vector<int> &V){
        if(root == NULL)
            return;

        inorder(root->left,V);
        V.push_back(root->val);
        inorder(root->right,V);
    }
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> A_Ans;
        inorder(root,A_Ans);

        return A_Ans;
    }
};