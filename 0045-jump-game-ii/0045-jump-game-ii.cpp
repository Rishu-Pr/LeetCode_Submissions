class Solution {
public:
    int jump(vector<int>& nums) {
        if(nums.size() == 1) return 0;
        int jumps = 0;
        int idx = 0;

        while(idx < nums.size()){
            if(idx + nums[idx] >= nums.size() - 1) return jumps + 1;
            int maxNum = idx + 1;
            for(int i = idx + 1; i <= idx + nums[idx]; i++){
                if (i + nums[i] > maxNum + nums[maxNum]) maxNum = i;
            }
            idx = maxNum;
            jumps++;
        }

        return jumps;
    }
};