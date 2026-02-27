class Solution {
public:
    int binarySearch(const vector<int>& arr, int s, int e, int x) {
        if (s > e)
            return -1;

        else {
        int mid = s + (e - s) / 2;
            if (arr[mid] == x)
                return mid;
            else if (arr[mid] < x)
                return binarySearch(arr, mid + 1, e, x);
            else
                return binarySearch(arr, s, mid - 1, x);
        }
        return -1;
    }

    int search(vector<int>& nums, int target) {
        int ans = binarySearch(nums, 0, nums.size() - 1, target);
        return ans;
    }
};