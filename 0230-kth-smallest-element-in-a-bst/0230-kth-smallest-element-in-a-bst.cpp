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
    void inOrder(TreeNode *root,vector<int> &V){
        if(root->left) inOrder(root->left,V);
        V.push_back(root->val);
        if(root->right) inOrder(root->right,V);
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        vector<int> V;
        inOrder(root,V);
        sort(V.begin(),V.end());
        return V[k-1];
    }
};