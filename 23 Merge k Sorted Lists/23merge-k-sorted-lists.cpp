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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<int, vector<int>, greater<int>> pq; // Max heap 
 
    for (int i = 0; i < lists.size(); i++) 
    { 
        while (lists[i] != NULL) 
        { 
            pq.push(lists[i]->val); 
            lists[i] = lists[i]->next; 
        } 
    } 
 
    struct ListNode *head = NULL; 
    struct ListNode *tail = NULL; 
 
    while (!pq.empty()) 
    { 
        struct ListNode *temp = new struct ListNode; 
        temp->val = pq.top(); 
        pq.pop(); 
        temp->next = NULL; 
 
        if (head == NULL) 
        { 
            head = temp; 
            tail = temp; 
        } 
        else 
        { 
            tail->next = temp; 
            tail = temp; 
        } 
    } 
    return head; 
    }
};