class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int size = nums.size();
        vector<int> V_Ans(size);

        for(int i=0;i<size;i++){
            V_Ans[(i+k)%size] = nums[i];
        }
        nums = V_Ans;
    }
};