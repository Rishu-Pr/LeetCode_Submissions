class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int ans = 1e8;
        for(int i = l; i <= r; i++){
            int sum = 0;
            for(int j = 0; j < i; j++){
                sum += nums[j];
            }
            if(sum > 0){
                ans = min(ans, sum);
            }
            for(int j = i; j < nums.size(); j++){
                sum += nums[j] - nums[j - i];
                if(sum > 0){
                    ans = min(ans, sum);
                }
            }
        }

        return (ans <= 0 || ans == 1e8) ? -1 : ans;
    }
};