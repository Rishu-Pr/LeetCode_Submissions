#define MOD 1000000007
class Solution {
    int solve(vector<int>& locations, int prev, int finish, int fuel, vector<vector<int>>& dp){
        if(fuel < 0) return 0;
        if(dp[prev][fuel] != -1) return dp[prev][fuel];
        int val = (prev == finish) ? 1 : 0;
        for(int i = 0; i < locations.size(); i++){
            if(i != prev){
                int new_fuel = fuel - abs(locations[prev] - locations[i]);
                val = (val + solve(locations, i, finish, new_fuel, dp)) % MOD;
            }
        }
        return dp[prev][fuel] = val;
    }
public:
    int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
        vector<vector<int>> dp(locations.size() + 1, vector<int>(fuel + 1, -1));
        return solve(locations, start, finish, fuel, dp);
    }
};