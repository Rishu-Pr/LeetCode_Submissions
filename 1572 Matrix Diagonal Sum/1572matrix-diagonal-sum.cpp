class Solution {
public:
    int diagonalSum(vector<vector<int>> &mat)
    {
        int sum = 0;
        int size = mat.size();
        for (int i = 0; i < size; i++)
        {
            sum += mat[i][i];
            sum += mat[size - 1 - i][i];
        }
        if (size % 2 == 1)
        {
            sum -= mat[size / 2][size / 2];
        }
        return sum;
    }
};