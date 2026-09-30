class Solution {
    int atMostK(vector<int>& nums, int k) {
        int l = 0, count = 0;
        unordered_map<int, int> freq;
        
        for (int r = 0; r < nums.size(); r++) {
            if (!freq[nums[r]]++) k--;
            
            while (k < 0) {
                if (!--freq[nums[l]]) k++;
                l++;
            }
            
            count += (r - l + 1);
        }
        
        return count;
    }
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atMostK(nums, k) - atMostK(nums, k - 1);
    }
};