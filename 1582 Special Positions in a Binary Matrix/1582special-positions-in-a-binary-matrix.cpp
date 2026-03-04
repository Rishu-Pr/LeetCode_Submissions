class Solution {
public:
    int numSpecial(vector<vector<int>> &mat)
    {
        int row = mat.size();
        int column = mat[0].size();
        int cnt = 0;
        vector<int> V_row_sum;
        vector<int> V_column_sum;
        for (int i = 0; i < column; i++)
        {
            int s = 0;
            for (int j = 0; j < row; j++)
                s += mat[j][i];

            V_row_sum.push_back(s);
        }
        for (int i = 0; i < row; i++)
        {
            int s = 0;
            for (int j = 0; j < column; j++)
                s += mat[i][j];

            V_column_sum.push_back(s);
        }

        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < column; j++)
                if (mat[i][j] == 1 && V_row_sum[j] == 1 && V_column_sum[i] == 1)
                    cnt++;
        }
        return cnt;
    }
};