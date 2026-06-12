#define MOD 1000000007

class Solution {
    int solve(string& s, int idx, vector<int>& dp){
        if(idx == s.size()) return 0;
        if(dp[idx] != -1) return dp[idx];

        int take = 0;
        vector<int> picked_chr(26, 0);
        for(int i = idx; i < s.size(); i++){
            int posn = s[i] - 'a';
            if(!picked_chr[posn]){
                picked_chr[posn] = 1;
                take = (take + 1 + solve(s, i + 1, dp)) % MOD;
            }
        }
        

        return dp[idx] = take;
    }
public:
    int distinctSubseqII(string s) {
        vector<int> dp(s.size(), -1);
        return solve(s, 0, dp);
    }
};