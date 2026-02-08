class Solution
{
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
        vector<int> V;
        int r = matrix.size();
        int c = matrix[0].size();

        int total = r * c, count = 0;
        int sRow = 0, sCol = 0, eRow = r - 1, eCol = c - 1;

        while (count < total)
        {
            for (int i = sCol; count < total && i <= eCol; i++)
            {
                V.push_back(matrix[sRow][i]);
                count++;
            }
            sRow++;

            for (int i = sRow; count < total && i <= eRow; i++)
            {
                V.push_back(matrix[i][eCol]);
                count++;
            }
            eCol--;

            for (int i = eCol; count < total && i >= sCol; i--)
            {
                V.push_back(matrix[eRow][i]);
                count++;
            }
            eRow--;

            for (int i = eRow; count < total && i >= sRow; i--)
            {
                V.push_back(matrix[i][sCol]);
                count++;
            }
            sCol++;
        }

        return V;
    }
};