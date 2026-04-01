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
    ListNode* insertionSortList(ListNode* head) {
        ListNode *first;
        ListNode *second = head->next;
        while(second){
            first =  head;
            while(first != second){
                if(first->val > second->val) swap(first->val,second->val);
                first = first->next;
            }
            second = second->next;
        }
        return head;
    }
};