class Solution {
    void fix(vector<vector<char>>& boxGrid, int i, int s, int e) {
        while (s < e) {
            if (boxGrid[i][s] == '.') s++;
            else if (boxGrid[i][e] == '#') e--;
            else { 
                swap(boxGrid[i][s], boxGrid[i][e]);
                s++;
                e--;
            }
        }
    }
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& boxGrid) {
        int row = boxGrid.size();
        int column = boxGrid[0].size();
        
        vector<vector<char>> Ans(column, vector<char>(row));

        for(int i = 0; i < row; i++){
            vector<int> solid;
            for(int j = 0; j < column; j++){
                if(boxGrid[i][j] == '*') solid.push_back(j);
            }
            solid.push_back(column);
            
            int s = 0;
            for(int t = 0; t < solid.size(); t++){
                int e = solid[t];
                fix(boxGrid, i, s, e - 1);
                s = e + 1; 
            }
        }

        for(int i = 0; i < row; i++){
            for(int j = 0; j < column; j++){
                Ans[j][row - 1 - i] = boxGrid[i][j];
            }
        }

        return Ans;
    }
};