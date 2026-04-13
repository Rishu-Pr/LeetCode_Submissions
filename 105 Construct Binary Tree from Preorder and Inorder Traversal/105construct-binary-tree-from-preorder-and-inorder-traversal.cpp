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

    int searchIdx(int val,vector<int>& inorder,int left,int right){
        for(int i = left; i <= right; i++){
            if(val == inorder[i])
                return i;
        }

        return -1;
    }

    TreeNode *createTree(vector<int>& preorder,vector<int>& inorder,int &preIdx,int left,int right){
        
        if(left > right)
            return NULL;

        TreeNode *root = new TreeNode(preorder[preIdx]);
        int inIdx = searchIdx(preorder[preIdx++],inorder,left,right);

        root->left = createTree(preorder,inorder,preIdx,left,inIdx-1);
        root->right = createTree(preorder,inorder,preIdx,inIdx+1,right);

        return root;
    }

public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int preIdx = 0;
        TreeNode *root = createTree(preorder,inorder,preIdx,0,preorder.size()-1);

        return root;
    }
};