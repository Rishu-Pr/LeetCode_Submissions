class Solution {
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        int msize = matrix.size();
        int nsize = matrix[0].size();
        int low = 0, high = msize * nsize - 1;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            int midElement = matrix[mid / nsize][mid % nsize];
            if (midElement == target)
                return true;
            else if (midElement < target)
                low = mid + 1;
            else
                high = mid - 1;
        }
        return false;
    }
};