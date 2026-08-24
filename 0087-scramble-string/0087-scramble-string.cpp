class Solution {
public:
    bool solve(string& s1, string& s2, int strt1, int strt2, int len, vector<vector<vector<int>>> &dp){
        if(s1.substr(strt1, len) == s2.substr(strt2, len)){
            return true;
        }
        if(len == 1){
            return false;
        }
        if(dp[strt1][strt2][len] != -1){
            return dp[strt1][strt2][len];
        }
        bool ans = false;
        for(int i = 1; i < len; i++){
            bool noscr = solve(s1, s2, strt1, strt2, i, dp) && solve(s1, s2, strt1 + i, strt2 + i, len - i, dp);
            bool scr = solve(s1, s2, strt1, strt2 + len - i, i, dp) && solve(s1, s2, strt1 + i, strt2, len - i, dp);

            ans = noscr || scr;
            if(ans){
                break;
            }
        }

        return dp[strt1][strt2][len] = ans;
    }
    bool isScramble(string s1, string s2) {
        if(s1.size() != s2.size()){
            return false;
        }
        vector<vector<vector<int>>> dp(31, vector<vector<int>>(31, vector<int>(31, -1)));
        return solve(s1, s2, 0, 0, s1.size(), dp);
    }
};