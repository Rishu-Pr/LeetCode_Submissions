class Solution
{
public:
    string reverseWords(string s)
    {
        string newStr = "";
        for (int i = 0; i < s.size();)
        {
            int j = i;
            int len = 0;

            if (s[i] != ' ')
            {
                while (s[i] != ' ')
                {
                    len++;
                    i++;
                    if (i == s.size())
                    {
                        break;
                    }
                }
                newStr.insert(newStr.begin(), s.begin() + j, s.begin() + j + len);
                newStr.insert(newStr.begin(), ' ');
            }
            else
            {
                i++;
            }
        }
        return newStr.substr(1, newStr.size() - 1);
    }
};