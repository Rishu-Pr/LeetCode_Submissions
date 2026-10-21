class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        // vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        vector<int> V1(m + 1, 0);
        vector<int> V2(m + 1, 0);
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                if(word1[i - 1] == word2[j - 1]){
                    V2[j] = 1 + V1[j - 1];
                }
                else{
                    V2[j] = max(V1[j], V2[j - 1]);
                }
            }
            V1 = V2;
        }

        return n + m - 2 * V2.back();
    }
};