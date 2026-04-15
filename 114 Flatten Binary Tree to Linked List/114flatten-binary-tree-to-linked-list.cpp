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
    void preOrder(TreeNode* root,vector<int> &ans){
        if(!root) return;

        ans.push_back(root->val);
        if(root->left) preOrder(root->left,ans);
        if(root->right) preOrder(root->right,ans);
    }

    void createLL(TreeNode** root,vector<int> &ans,int &idx){
        if(!(*root)){
            *root = new TreeNode(ans[idx++]);
            return;
        }
        TreeNode *ittr = *root;
        while(idx < ans.size()){
            TreeNode *temp = new TreeNode(ans[idx++]);
            ittr->right = temp;
            ittr->left = NULL;
            ittr = ittr->right;
        }
    }

public:
    void flatten(TreeNode* root) {
        if(!root || (!root->left && !root->right)) return;
        vector<int> ans;
        preOrder(root,ans);

        int idx = 1;
        createLL(&root,ans,idx);
    }
};