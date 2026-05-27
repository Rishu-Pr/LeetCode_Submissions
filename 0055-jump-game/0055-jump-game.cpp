class Solution {
public:
    bool canJump(vector<int>& nums) {
        if(nums.size() == 1) return true;
        int idx = 0;
        
        while(idx < nums.size() - 1){
            if(idx + nums[idx] >= nums.size() - 1) return true;
            int maxNum = idx + 1;
            if(nums[idx] == 0) return false;
            for(int i = idx + 1; i <= idx + nums[idx]; i++){
                if(i + nums[i] > maxNum + nums[maxNum]) maxNum = i;
            }
            idx = maxNum;
        }
        return false;
    }
};