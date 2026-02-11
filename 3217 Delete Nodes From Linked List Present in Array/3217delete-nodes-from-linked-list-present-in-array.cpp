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
    ListNode *modifiedList(vector<int> &nums, ListNode *head)
    {
        sort(nums.begin(),nums.end());
        ListNode *temp = head;
        ListNode *prev = NULL;
        while (temp != NULL)
        {
            if (upper_bound(nums.begin(), nums.end(), temp->val) - lower_bound(nums.begin(), nums.end(), temp->val))
            {
                if (temp == head)
                {
                    head = temp->next;
                    temp = head;
                }
                else
                {
                    prev->next = temp->next;
                    temp = prev->next;
                }
            }
            else
            {
                prev = temp;
                temp = temp->next;
            }
        }
        return head;
    }
};