class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int peakIdx = nums.size() - 1;
        int curr = nums.size() - 2;

        while(curr >= 0 && nums[curr] >= nums[peakIdx]){
            peakIdx = curr;
            curr--;
        }

        int idx1 = peakIdx;
        int idx2 = nums.size() - 1;
        if(curr != -1){
            while(nums[idx2] <= nums[curr] && idx2 > curr){
                idx2--;
            }
            swap(nums[curr], nums[idx2]);
        }
        idx2 = nums.size() - 1;
        while(idx1 < idx2){
            swap(nums[idx1], nums[idx2]);
            idx1++; idx2--;
        }
    }
};