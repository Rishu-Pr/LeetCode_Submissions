class Solution {
public:
    int subarrayGCD(vector<int>& nums, int k) {
        // sort(nums.begin(), nums.end());

        // int start = 0;
        // while(start < nums.size() && nums[start] < k){
        //     start++;
        // }

        int count = 0;

        for(int i = 0; i < nums.size(); i++){
            int gcd_Sum = nums[i];
            for(int j = i; j < nums.size(); j++){
                gcd_Sum = gcd(gcd_Sum, nums[j]);
                if(gcd_Sum == k){
                    count++;
                }
                if(gcd_Sum < k){
                    break;
                }
            }
        }

        return count;
    }
};