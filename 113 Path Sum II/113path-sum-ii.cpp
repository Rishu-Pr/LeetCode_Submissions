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
    void findSum(TreeNode* root,int &sum, int targetSum,vector<vector<int>> &Ans,vector<int> &temp){
        sum += root->val;
        temp.push_back(root->val);
        if(!root->left && !root->right && sum == targetSum)
            Ans.push_back(temp);

        if(root->left) findSum(root->left,sum,targetSum,Ans,temp);
        if(root->right) findSum(root->right,sum,targetSum,Ans,temp);
        
        temp.pop_back();
        sum -= root->val;
    }
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> Ans;
        if(!root) return Ans;
        vector<int> temp;
        int sum = 0;
        findSum(root,sum,targetSum,Ans,temp);

        return Ans;
    }
};