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
    vector<vector<int>> spiralMatrix(int m, int n, ListNode *head)
    {
        int upperR = 0;
        int lowerR = m - 1;
        int leftC = 0;
        int rightC = n - 1;
        int total = m * n, cnt = 0;
        vector<vector<int>> V(m, vector<int>(n, 0));

        while (cnt < total)
        {
            for (int i = leftC; i <= rightC && cnt < total; i++)
            {
                if (head == NULL)
                {
                    V[upperR][i] = -1;
                }
                else
                {
                    V[upperR][i] = head->val;
                    head = head->next;
                }
                cnt++;
            }
            upperR++;

            for (int i = upperR; i <= lowerR && cnt < total; i++)
            {
                if (head == NULL)
                {
                    V[i][rightC] = -1;
                }
                else
                {
                    V[i][rightC] = head->val;
                    head = head->next;
                }
                cnt++;
            }
            rightC--;

            for (int i = rightC; i >= leftC && cnt < total; i--)
            {
                if (head == NULL)
                {
                    V[lowerR][i] = -1;
                }
                else
                {
                    V[lowerR][i] = head->val;
                    head = head->next;
                }
                cnt++;
            }
            lowerR--;

            for (int i = lowerR; i >= upperR && cnt < total; i--)
            {
                if (head == NULL)
                {
                    V[i][leftC] = -1;
                }
                else
                {
                    V[i][leftC] = head->val;
                    head = head->next;
                }
                cnt++;
            }
            leftC++;
        }

        return V;
    }
};