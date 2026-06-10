#define MOD 1000000007
class Solution {
    int solve(string& target, int idx_w, int idx_trg, vector<vector<int>>& dp, vector<vector<int>>& freq){
        if(idx_trg == target.size()) return 1;
        if(idx_w == freq.size()) return 0;

        if(dp[idx_w][idx_trg] != -1) return dp[idx_w][idx_trg];

        long long ans = solve(target, idx_w + 1, idx_trg, dp, freq);

        int c = target[idx_trg] - 'a';
        if(freq[idx_w][c] > 0){
            ans = (ans + 1LL * freq[idx_w][c] * solve(target, idx_w + 1, idx_trg + 1, dp, freq)) % MOD;
        }

        return dp[idx_w][idx_trg] = ans % MOD;
    }
public:
    int numWays(vector<string>& words, string target) {
        vector<vector<int>> freq(words[0].size(), vector<int>(26, 0));
        for(string& w : words){
            for(int i = 0; i < words[0].size(); i++){
                freq[i][w[i] - 'a']++;
            }
        }
        vector<vector<int>> dp(words[0].size() + 1, vector<int>(target.size(), -1));
        return solve(target, 0, 0, dp, freq);
    }
};