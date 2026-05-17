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
    int solve(TreeNode* root, unordered_map<TreeNode*, int>& p){
        if(!root) return 0;
        if(!root->left && !root->right) return root->val;

        if(p.count(root)) return p[root];

        int inc =  root->val;
        if(root->left)
            inc += solve(root->left->left, p) + solve(root->left->right, p);
        if(root->right)
            inc += solve(root->right->left, p) + solve(root->right->right, p);
        int exc = solve(root->left, p) + solve(root->right, p);

        p[root] = max(inc, exc);
        return p[root];
    }
public:
    int rob(TreeNode* root) {
        unordered_map<TreeNode*, int> p;
        int ans = solve(root, p);
        return ans;
    }
};