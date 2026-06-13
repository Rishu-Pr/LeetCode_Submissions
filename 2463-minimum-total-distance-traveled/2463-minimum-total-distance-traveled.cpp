class Solution {
    long long solve(vector<int>& robot, vector<int>& fact, int idx1, int idx2, vector<vector<long long>>& dp){
        if(idx1 == robot.size()) return 0;
        if(idx2 == fact.size()) return 2e15;
        if(dp[idx1][idx2] != 1e15) return dp[idx1][idx2];

        long long skip = solve(robot, fact, idx1, idx2 + 1, dp);
        long long take = abs(robot[idx1] - fact[idx2]) + solve(robot, fact, idx1 + 1, idx2 + 1, dp);

        return dp[idx1][idx2] = min(skip, take);
    }
public:
    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        vector<int> fact;
        for(int i = 0; i < factory.size(); i++){
            for(int j = factory[i][1]; j > 0; j--){
                fact.push_back(factory[i][0]);
            }
        }

        vector<vector<long long>> dp(robot.size(), vector<long long>(fact.size(), 1e15));
        sort(robot.begin(), robot.end());
        sort(fact.begin(), fact.end());

        return solve(robot, fact, 0, 0, dp);
    }
};