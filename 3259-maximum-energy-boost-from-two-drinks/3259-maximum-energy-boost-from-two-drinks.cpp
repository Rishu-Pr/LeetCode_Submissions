class Solution {
    long long solve(vector<int>& energyDrinkA, vector<int>& energyDrinkB, int idx, int num, vector<vector<long long>>& dp){
        if(idx >= energyDrinkA.size()){
            return 0;
        }
        if(dp[idx][num] != -1){
            return dp[idx][num];
        }

        int val = 0;
        if(num == 0){
            val = energyDrinkA[idx];
        }
        else{
            val = energyDrinkB[idx];
        }
        long long maxV = solve(energyDrinkA, energyDrinkB, idx + 1, num, dp) + val;
        if(idx < energyDrinkA.size() - 1){
            maxV = max(maxV, solve(energyDrinkA, energyDrinkB, idx + 2, (num + 1) % 2, dp) + val);
        }

        return dp[idx][num] = maxV;
    }
public:
    long long maxEnergyBoost(vector<int>& energyDrinkA, vector<int>& energyDrinkB) {
        vector<vector<long long>> dp(energyDrinkA.size(), vector<long long>(2, -1));
        long long ans = solve(energyDrinkA, energyDrinkB, 0, 0, dp);
        ans = max(ans, solve(energyDrinkA, energyDrinkB, 0, 1, dp));
        return ans;
    }
};