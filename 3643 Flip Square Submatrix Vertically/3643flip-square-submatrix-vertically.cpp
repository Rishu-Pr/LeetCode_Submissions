class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {

        int i = 0;

        while (i < k) {
            int j = 0;
            while (j < k/2) {
                swap(grid[x+j][y + i], grid[x+k-1-j][y + i]);
                j++;
            }
            i++;
        }
        return grid;
    }
};