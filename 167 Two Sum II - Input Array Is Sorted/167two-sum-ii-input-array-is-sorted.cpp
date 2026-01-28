class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target)
    {
        int left = 0;
        int right = numbers.size() - 1;
        vector<int> V_ans;

        while (left < right)
        {
            int sum = numbers[left] + numbers[right];
            if (sum == target)
            {
                V_ans.push_back(left + 1);
                V_ans.push_back(right + 1);
                return V_ans;
            }
            else if (sum > target)
            {
                right--;
            }
            else
            {
                left++;
            }
        }
        return {-1, -1};
    }
};