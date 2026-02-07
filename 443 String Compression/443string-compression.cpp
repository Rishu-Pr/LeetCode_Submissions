class Solution {
public:
    int compress(vector<char> &chars)
    {
        string str = "";
        for (int i = 0; i < chars.size();)
        {
            int cnt = 0;
            char chr = chars[i];
            while (i<chars.size() && chars[i] == chr)
            {
                cnt++;
                i++;
            }
            str.push_back(chars[i - 1]);
            if (cnt > 1)
            {
                str += to_string(cnt);
            }
        }
        chars.clear();
        for (int i = 0; i < str.length(); i++)
            chars.push_back(str[i]);

        return str.length();
    }
};