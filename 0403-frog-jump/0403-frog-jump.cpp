// class Solution {
//     bool solve(vector<int>& stones, int posn, int steps){
//         if(steps < 1) return false;
//         if(posn == stones.size() - 1) return true;
        
//         int new_stone = stones[posn] + steps;
//         int next_posn = posn + 1;
//         while(next_posn < stones.size() && stones[next_posn] < new_stone) next_posn++;

//         if(next_posn == stones.size() || stones[next_posn] != new_stone) return false; 

//         bool way1 = solve(stones, next_posn, steps - 1);
//         bool way2 = solve(stones, next_posn, steps);
//         bool way3 = solve(stones, next_posn, steps + 1);

//         return way1 || way2 || way3;
//     }
// public:
//     bool canCross(vector<int>& stones) {
//         return solve(stones, 0, 1);
//     }
// };

class Solution {
    bool solve(vector<int>& stones, int posn, int steps, vector<vector<int>>& dp){
        if(steps < 1) return false;
        if(posn == stones.size() - 1) return true;

        if(dp[posn][steps] != -1) return dp[posn][steps];
    
        int new_stone = stones[posn] + steps;
        int next_posn = posn + 1;
        while(next_posn < stones.size() && stones[next_posn] < new_stone) next_posn++;

        if(next_posn == stones.size() || stones[next_posn] != new_stone){
            dp[posn][steps] = false;
            return dp[posn][steps];
        } 

        bool way1 = solve(stones, next_posn, steps - 1, dp);
        bool way2 = solve(stones, next_posn, steps, dp);
        bool way3 = solve(stones, next_posn, steps + 1, dp);

        dp[posn][steps] = (way1 || way2 || way3);
        return dp[posn][steps];
    }
public:
    bool canCross(vector<int>& stones) {
        int n = stones.size();
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));
        return solve(stones, 0, 1, dp);
    }
};