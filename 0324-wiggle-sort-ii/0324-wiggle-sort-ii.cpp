class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int start1 = (nums.size() - 1) / 2;
        int start2 = nums.size() - 1;

        vector<int> temp = nums;
        int idx = 0;
        while(start1 >= 0 && start2 >= (nums.size() + 1) / 2){
            nums[idx++] = temp[start1--];
            nums[idx++] = temp[start2--];
        }
        while(start1 >= 0){
            nums[idx++] = temp[start1--];
        }
    }
};