class Solution {
public:
    int numDistinct(string s, string t) {
        vector<unsigned long long> prev(t.size() + 1, 0); prev[t.size()] = 1;
        vector<unsigned long long> curr(t.size() + 1, 0); curr[t.size()] = 1;

        for(int idx_s = s.size() - 1; idx_s >= 0; idx_s--){
            for(int idx_T = t.size() - 1; idx_T >= 0; idx_T--){
                if(s[idx_s] == t[idx_T]) curr[idx_T] = prev[idx_T] + prev[idx_T + 1];
                else curr[idx_T] = prev[idx_T];
            }

            prev = curr;
        }
        return prev[0];
    }
};