class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        int n = wall.size();
        unordered_map<long long, int> map;
        int maxV = 0;
        
        for(int i = 0; i < n; i++) {
            long long prefixSum = 0;
            
            for(int j = 0; j < wall[i].size() - 1; j++) {
                prefixSum += wall[i][j];
                map[prefixSum]++;
                
                maxV = max(maxV, map[prefixSum]);
            }
        }
        
        return n - maxV;
    }
};