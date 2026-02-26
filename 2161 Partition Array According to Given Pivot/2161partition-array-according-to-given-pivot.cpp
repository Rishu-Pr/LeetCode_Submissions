class Solution {
public:
    vector<int> pivotArray(vector<int> &nums, int pivot)
    {
        vector<int> V;
        int gotPivot = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == pivot)
            {
                nums[i] = INT32_MIN;
                gotPivot++;
            }
            else if (nums[i] < pivot)
            {
                V.push_back(nums[i]);
                nums[i] = INT32_MIN;
            }
        }
        
        for (int i = 0; i < gotPivot; i++)
            V.push_back(pivot);

        for (int i = 0; i < nums.size(); i++)
            if (nums[i] >= pivot) V.push_back(nums[i]);

        return V;
    }
};