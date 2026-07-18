class Solution {
public:
    int subarrayLCM(vector<int>& nums, int k) {
        int count = 0;

        for(int i = 0; i < nums.size(); i++){
            int lcm_Sum = nums[i];
            for(int j = i; j < nums.size(); j++){
                if (k % nums[j] != 0) {
                    break;
                }
                lcm_Sum = lcm(lcm_Sum, nums[j]);
                if(lcm_Sum == k){
                    count++;
                }
            }
        }

        return count;
    }
};