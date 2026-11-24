class Solution {
public:
    int maxLength(vector<int>& nums) {
        int n = nums.size();
        int ans = 2;
        int left = 0;
        int curr = 1;
        for(int i = 0; i < n; i++){
            while(gcd(curr, nums[i]) > 1){
                curr /= nums[left];
                left++;
            }
            curr *= nums[i];
            ans = max(ans, i - left + 1);
        }

        return ans;
    }
};