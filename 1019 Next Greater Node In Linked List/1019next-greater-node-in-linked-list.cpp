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
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> V;
    while (head != NULL)
    {
        V.push_back(head->val);
        head = head->next;
    }

    vector<int> result(V.size(), 0);
    stack<int> st;

    for (int i = 0; i < V.size(); i++)
    {
        while (!st.empty() && V[i] > V[st.top()])
        {
            result[st.top()] = V[i];
            st.pop();
        }

        st.push(i);
    }
    return result;
    }
};