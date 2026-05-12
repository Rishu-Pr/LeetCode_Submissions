class Solution
{
public:
    bool isValidSerialization(string preorder)
    {
        stack<string> stk;
        vector<string> str_vector;
        for (int i = 0; i < preorder.size(); i++)
        {
            string s = "";
            while (i < preorder.size() && preorder[i] != ',')
            {
                s.push_back(preorder[i]);
                i++;
            }
            str_vector.push_back(s);
        }
        for (int i = 0; i < str_vector.size(); i++)
        {
            stk.push(str_vector[i]);

            while (stk.size() >= 3)
            {
                string top1 = stk.top();
                stk.pop();
                string top2 = stk.top();
                stk.pop();
                string top3 = stk.top();
                stk.pop();

                if (top1 == "#" && top2 == "#" && top3 != "#")
                {
                    stk.push("#");
                }
                else
                {
                    stk.push(top3);
                    stk.push(top2);
                    stk.push(top1);
                    break;
                }
            }
        }
        return (stk.size() == 1 && stk.top() == "#");
    }
};