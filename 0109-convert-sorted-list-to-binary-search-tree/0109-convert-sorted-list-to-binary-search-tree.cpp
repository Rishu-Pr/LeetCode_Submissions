/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    TreeNode* createTree(vector<int>& V,int low,int high){
        if(low > high) return NULL;
        int mid = low + (high - low) / 2;
        TreeNode* r = new TreeNode(V[mid]);
        if(low < high){
            r->left = createTree(V, low, mid - 1);
            r->right = createTree(V, mid + 1, high);
        }
        return r;
    }
public:
    TreeNode* sortedListToBST(ListNode* head) {
        if(!head) return NULL;
        vector<int> V;
        ListNode* root = head;
        while(root){
            V.push_back(root->val);
            root = root->next;
        }

        TreeNode* r = createTree(V, 0, V.size() - 1);
        return r;
    }
};