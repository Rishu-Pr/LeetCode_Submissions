class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<int> rowS;
        vector<int> colS;
        for(int i = 0; i < n; i++){
            int sum = 0;
            for(int j = 0; j < m; j++){
                sum += grid[i][j];
            }
            rowS.push_back(sum);
        }
        
        for(int i = 0; i < m; i++){
            int sum = 0;
            for(int j = 0; j < n; j++){
                sum += grid[j][i];
            }
            colS.push_back(sum);
        }

        int cnt = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 1 && rowS[i] * colS[j] > 1){
                    cnt++;
                }
            }
        }

        return cnt;
    }
};