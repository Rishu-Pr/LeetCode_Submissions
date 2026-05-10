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
    long ans = LONG_MAX;
    void getSec(TreeNode* root, int &min){
        if(!root) return;

        if(root->val > min && root->val < ans)
            ans = root->val;

        getSec(root->left,min);
        getSec(root->right,min);
    }

    int findSecondMinimumValue(TreeNode* root) {
        int min = root->val;
        getSec(root,min);

        if(ans == LONG_MAX) return -1;
        else return ans;
    }
};