class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        int count = 0;
        for (int t = 0; t < words.size(); t++) {
            int i = 0, j = 0;

            while (i < s.size() && j < words[t].size()) {
                if (words[t][j] == s[i]) j++;
                i++;
            }

            if (j == words[t].size()) {
                count++;
                while (t < words.size() - 1 && words[t] == words[t + 1]) {
                    t++;
                    count++;
                }
            } else {
                while (t < words.size() - 1 && words[t] == words[t + 1]) t++;
            }
        }
        return count;
    }
};