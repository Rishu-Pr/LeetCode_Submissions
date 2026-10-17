class Solution {
    // int isPalid(string s){
    //     int i = 0; 
    //     int j = s.size() - 1;
    //     int cnt = 0;
    //     while(i < j){
    //         if(s[i] != s[j]){
    //             cnt++;
    //         }
    //         i++;
    //         j--;
    //     }

    //     return cnt;
    // }

    int solve(string& s, int k, vector<vector<int>>& V, int idx, vector<vector<int>>& dp){
        if(k < 0){
            return 1e8;
        }
        if(idx == s.size()){
            if(k != 0){
                return 1e8;
            }
            return 0;
        }

        if(dp[idx][k] != -1){
            return dp[idx][k];
        }

        int ans = 1e8;
        for(int i = idx; i < s.size(); i++){
            ans = min(ans, V[idx][i] + solve(s, k - 1, V, i + 1, dp));
        }

        return dp[idx][k] = ans;
    }
public:
    int palindromePartition(string s, int k) {
        int n = s.size();
        vector<vector<int>> V(n, vector<int>(n, 0));
        for(int i = n - 1; i >= 0; i--){
            for(int j = i; j < n; j++){
                if(j == i){
                    V[i][j] = 0;
                }
                else if(j - i == 1){
                    if(s[i] != s[j]){
                        V[i][j] = 1;
                    }
                    else{
                        V[i][j] = 0;
                    }
                }
                else{
                    V[i][j] = V[i + 1][j - 1];
                    if(s[i] != s[j]){
                        V[i][j] += 1;
                    }
                }
            }
        }

        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));

        return solve(s, k, V, 0, dp);
    }
};