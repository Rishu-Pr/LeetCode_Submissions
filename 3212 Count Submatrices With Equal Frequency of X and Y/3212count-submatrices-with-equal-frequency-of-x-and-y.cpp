class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int count=0;

        vector<int> colX(grid[0].size(),0);
        vector<int> colY(grid[0].size(),0);

        for(int i=0 ; i < grid.size() ;i++){
            int cntX=0;
            int cntY=0;
            for(int j=0; j<grid[0].size();j++){
                if(grid[i][j]=='X') colX[j]++;
                else if(grid[i][j]=='Y') colY[j]++;

                cntX += colX[j];
                cntY += colY[j];

                if(cntX>0 && cntX==cntY) count++;
            }
        }

        return count;
    }
};