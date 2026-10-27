class Solution {
public:
    vector<string> createGrid(int m, int n) {
        vector<string> V(m, string(n, '#'));
        for(int i = 0; i < n; i++){
            V[0][i] = '.';
        }
        for(int i = 0; i < m; i++){
            V[i][n - 1] = '.';
        }

        return V;
    }
};