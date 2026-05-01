/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

struct TreeNode *findMin(struct TreeNode *root){
    while(root->left)
        root = root->left;
    
    return root;
}

struct TreeNode* deleteNode(struct TreeNode* root, int key) {
    if(!root) return NULL;

    if(key < root->val){
        root->left = deleteNode(root->left,key);
    }
    else if(key > root->val){
        root->right = deleteNode(root->right,key);
    }
    else{
        if(!root->left && !root->right){
            free(root);
            return NULL;
        }
        else if(!root->left){
            struct TreeNode *temp = root->right;
            free(root);
            return temp;
        }
        else if(!root->right){
            struct TreeNode *temp = root->left;
            free(root);
            return temp;
        }
        else{
            struct TreeNode *temp = findMin(root->right);
            root->val = temp->val;
            root->right = deleteNode(root->right,temp->val);
            
        }
    }
    return root;
}