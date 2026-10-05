class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        for(int i = 0; i < nums.size(); i++){
            nums[i] = abs(nums[i]);
        }
        sort(nums.begin(), nums.end());

        long long val = 0;
        int s = 0;
        int e = nums.size() - 1;

        while( s <= e){
            val += nums[e] * nums[e];
            e--;
            if(s <= e){
                val -= nums[s] * nums[s];
                s++;
            }
        }

        return val;
    }
};