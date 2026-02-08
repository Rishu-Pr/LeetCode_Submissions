class Solution
{
public:
    void rotate(vector<vector<int>> &matrix)
    {
        int r_size = matrix.size() - 1, c_size = matrix[0].size() - 1;
        for (int i = 0; i <= r_size; i++)
        {
            for (int j = i; j <= c_size; j++)
            {
                int temp = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = temp;
            }
        }

        for (int i = 0; i <= r_size; i++)
        {
            for (int j = 0; j <= c_size / 2; j++)
            {
                int temp = matrix[i][j];
                matrix[i][j] = matrix[i][c_size - j];
                matrix[i][c_size - j] = temp;
            }
        }
    }
};