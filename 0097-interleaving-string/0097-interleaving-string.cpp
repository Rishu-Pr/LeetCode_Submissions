class Solution {
    bool solve(string& s1, string& s2, string& s3, int s1_idx, int s2_idx, int s3_idx, vector<vector<int>>& dp){
        if(s1_idx == s1.size() && s2_idx == s2.size() && s3_idx == s3.size()) return true;
        if(dp[s1_idx][s2_idx] != -1) return dp[s1_idx][s2_idx];

        bool match1 = (s1[s1_idx] == s3[s3_idx]) ? solve(s1, s2, s3, s1_idx + 1, s2_idx, s3_idx + 1, dp) : false;
        bool match2 = (s2[s2_idx] == s3[s3_idx]) ? solve(s1, s2, s3, s1_idx, s2_idx + 1, s3_idx + 1, dp) : false;

        return dp[s1_idx][s2_idx] = (match1 || match2);
    }
public:
    bool isInterleave(string s1, string s2, string s3) {
        vector<vector<int>> dp(s1.size() + 1, vector<int>(s2.size() + 1, -1));
        return (s1.size() + s2.size() == s3.size()) ? solve(s1, s2, s3, 0, 0, 0, dp) : false;
    }
};
