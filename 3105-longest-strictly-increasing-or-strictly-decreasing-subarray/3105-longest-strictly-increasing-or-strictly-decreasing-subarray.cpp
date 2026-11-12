class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int ans = 1;
        int temp = 1;
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] > nums[i - 1]){
                temp++;
            }
            else{
                ans = max(ans, temp);
                temp = 1;
            }
        }
        ans = max(ans, temp);
        temp = 1;

        for(int i = 1; i < nums.size(); i++){
            if(nums[i] < nums[i - 1]){
                temp++;
            }
            else{
                ans = max(ans, temp);
                temp = 1;
            }
        }

        return max(ans, temp);
    }
};