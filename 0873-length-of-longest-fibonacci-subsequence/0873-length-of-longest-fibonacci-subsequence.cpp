class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        unordered_map<int, int> map;
        for(int i = 0; i < arr.size(); i++){
            map[arr[i]] = i;
        }
        int maxLen = 0;
        vector<vector<int>> dp(arr.size(), vector<int>(arr.size(), 0));

        for(int i = 0; i < arr.size(); i++){
            for(int j = 0; j < i; j++){
                int Val = arr[i] - arr[j];

                if(Val < arr[j] && map.count(Val)){
                    int v = map[Val];

                    dp[j][i] = (dp[v][j] == 0 ? 2 : dp[v][j]) + 1;
                    maxLen = max(maxLen, dp[j][i]);
                }
            }
        }

        return maxLen;
    }
};