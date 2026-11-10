class Solution {
    int solve(int i, int n, vector<int>& costs, unordered_map<int, int>& map) {
        if (i == n) {
            return 0;
        }
        if(map.count(i)){
            return map[i];
        }

        int min_cost = INT_MAX;

        if (i + 1 <= n) {
            int cost = costs[i] + 1 + solve(i + 1, n, costs, map);
            min_cost = min(min_cost, cost);
        }

        if (i + 2 <= n) {
            int cost = costs[i + 1] + 4 + solve(i + 2, n, costs, map);
            min_cost = min(min_cost, cost);
        }

        if (i + 3 <= n) {
            int cost = costs[i + 2] + 9 + solve(i + 3, n, costs, map);
            min_cost = min(min_cost, cost);
        }

        return map[i] = min_cost;
    }

public:
    int climbStairs(int n, vector<int>& costs) {
        unordered_map<int, int> map;
        return solve(0, n, costs, map);
    }
};