class Solution {
    bool solve(string& s, vector<string>& wordDict, int idx, vector<int>& dp){
        if(idx == s.size()) return true;
        if(dp[idx] != -1) return dp[idx];

        for(int i = 0; i < wordDict.size(); i++){
            if(wordDict[i][0] == s[idx]){
                int j = 0;
                int k = idx;
                while(wordDict[i][j] == s[k] && j < wordDict[i].size() && k < s.size()){
                    j++; k++;
                }
                if(j == wordDict[i].size() && solve(s, wordDict, k, dp)) return dp[idx] = true; 
            }
        }
        return dp[idx] = false;
    }
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<int> dp(s.size(), -1);
        return solve(s, wordDict, 0, dp);
    }
};