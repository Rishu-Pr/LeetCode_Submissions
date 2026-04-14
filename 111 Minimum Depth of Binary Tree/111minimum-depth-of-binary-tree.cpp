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
    int minHeight = INT_MAX;

    void height(TreeNode* root,int num){
        if (!root->left && !root->right){
            minHeight = min(minHeight,num);
            return;
        }

        if(root->left) height(root->left,num+1);
        if(root->right) height(root->right,num+1);
    }
public:
    int minDepth(TreeNode* root) {
        if(!root) return 0;
        if(!root->left && !root->right) return 1;
        if(root->left) height(root->left,2);
        if(root->right) height(root->right,2);

        return minHeight;
    }
};