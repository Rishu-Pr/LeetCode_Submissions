class Solution {
public:
    vector<vector<int>> generateMatrix(int n)
    {
        vector<vector<int>> V(n, vector<int>(n));
        int top = 0, right = n - 1, bottom = n - 1, left = 0, num = 1;
        while (top <= bottom)
        {
            for (int i = left; i <= right; i++)
                V[top][i] = (num++);
            
            top++;

            for (int i = top; i <= bottom; i++)
                V[i][right] = (num++);
            
            right--;

            for (int i = right; i >= left; i--)
                V[bottom][i] = (num++);
            
            bottom--;

            for (int i = bottom; i >= top; i--)
                V[i][left] = (num++);
            
            left++;
        }
        return V;
    }
};