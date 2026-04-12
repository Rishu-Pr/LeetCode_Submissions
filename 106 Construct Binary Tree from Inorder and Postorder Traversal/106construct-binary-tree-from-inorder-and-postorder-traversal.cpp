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

    int searchIdx(int val,vector<int> inorder,int left,int right){
        for(int i = left; i <= right; i++)
            if(inorder[i] == val)
                return i;
        
        return -1;
    }

    TreeNode *create(vector<int>& inorder,vector<int>& postOrder,int& postIdx,int left,int right){

        if(left > right)
            return NULL;
        
        TreeNode *root = new TreeNode(postOrder[postIdx]);
        int inIdx = searchIdx(postOrder[postIdx--],inorder,left,right);

        root->right = create(inorder,postOrder,postIdx,inIdx+1,right);
        root->left = create(inorder,postOrder,postIdx,left,inIdx-1);

        return root;
    }

public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int postIdx = postorder.size()-1;
        TreeNode *root = NULL;
        return create(inorder,postorder,postIdx,0,postorder.size()-1);
    }
};