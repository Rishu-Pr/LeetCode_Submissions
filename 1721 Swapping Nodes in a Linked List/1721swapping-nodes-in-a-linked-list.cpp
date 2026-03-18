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
class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode *Node1=head;
        ListNode *Node2=head;
        int len = 0;
        while(Node1){
            len++;
            Node1 = Node1->next;
        } 
        Node1 = head;
        int s = k;
        for(int i = 0; i < k-1;i++){
            Node1 = Node1->next;
        }

        for(int i = 0; i < len-k;i++){
            Node2 = Node2->next;
        }

        int temp = Node1->val;
        Node1->val = Node2->val;
        Node2->val = temp;
        return head;
    }
};