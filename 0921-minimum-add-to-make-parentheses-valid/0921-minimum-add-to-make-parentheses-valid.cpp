class Solution {
public:
    int minAddToMakeValid(string s)
    {
        int bal = 0;
        int add = 0;

        for (auto c : s)
        {
            if (c == '(')
                bal++;
            else
            {
                if (bal > 0)
                    bal--;
                else
                    add++;
            }
        }
        return add + bal;
    }
};