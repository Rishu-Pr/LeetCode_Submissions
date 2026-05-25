class Solution {
public:
    int maxSizeSlices(vector<int>& slices) {
        int size = slices.size();
        vector<vector<int>> dp1(size + 2, vector<int>(size + 1, 0));
        vector<vector<int>> dp2(size + 2, vector<int>(size + 1, 0));
        
        for(int i = size - 2; i >= 0; i--){
            for(int j = 1; j <= size / 3; j++){
                int take = slices[i] + dp1[i + 2][j - 1];
                int notTake = dp1[i + 1][j];

                dp1[i][j] = max(take, notTake);
            }
        }
        
        for(int i = size - 1; i >= 1; i--){
            for(int j = 1; j <= size / 3; j++){
                int take = slices[i] + dp2[i + 2][j - 1];
                int notTake = dp2[i + 1][j];

                dp2[i][j] = max(take, notTake);
            }
        }

        return max(dp1[0][size / 3], dp2[1][size / 3]);
    }
};