/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* insertIntoBST(struct TreeNode* root, int val) {
    if(!root){
        struct TreeNode* temp = (struct TreeNode*)malloc(sizeof(struct TreeNode));
        temp->val = val;
        temp->left = NULL;
        temp->right = NULL;

        return temp;
    }
    if(val < root->val)
        root->left = insertIntoBST(root->left,val);
    else
        root->right = insertIntoBST(root->right,val);
    
    return root;
}