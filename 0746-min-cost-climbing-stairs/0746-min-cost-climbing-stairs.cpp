class Solution {
    
public: 
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        
        int prev1 = cost[0];
        int prev2 = cost[1];
        int curr;

        for(int i = 2; i < n; i++){
            curr = min(prev1, prev2) + cost[i];
            prev1 = prev2;
            prev2 = curr;
        }
        return min(prev1, prev2);
    }
};