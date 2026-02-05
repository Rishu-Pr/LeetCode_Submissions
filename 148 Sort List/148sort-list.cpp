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
    ListNode* sortList(ListNode* head) {
        int cnt = 0;
    ListNode *temp = head;
    while (temp != NULL)
    {
        cnt++;
        temp = temp->next;
    }

    temp = head;
    vector<int> V(cnt, 0);
    for (int i = 0; i < cnt; i++)
    {
        V[i] = temp->val;
        temp = temp->next;
    }
    sort(V.begin(), V.end());

    temp = head;
    for (int i = 0; i < cnt; i++)
    {
        temp->val = V[i];
        temp = temp->next;
    }
    return head;
    }
};