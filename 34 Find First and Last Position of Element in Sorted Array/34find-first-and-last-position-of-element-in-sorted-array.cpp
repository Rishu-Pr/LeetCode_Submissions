class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans = {-1, -1};
        if (nums.empty())
            return ans;
        int low = 0, high = nums.size() - 1;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (nums[mid] >= target)
                high = mid - 1;
            else
                low = mid + 1;
        }
        if (low < nums.size() && nums[low] == target)
            ans[0] = low;
        else
            return ans;
        high = nums.size() - 1;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (nums[mid] <= target)
                low = mid + 1;
            else
                high = mid - 1;
        }
        ans[1] = high;
        return ans;
    }
};