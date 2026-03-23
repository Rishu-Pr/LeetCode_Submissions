class Solution {
public:
    char kthCharacter(int k) {
        string str = "a";

        while (str.length() < k) {
            int n = str.size();
            for (int i = 0; i < n; i++)
                str.push_back(str[i] + 1);
        }

        return str[k - 1];
    }
};