class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int maxNum = nums[0];
        for(int i = 1; i < nums.size(); i++){
            if(maxNum < nums[i]){
                maxNum = nums[i];
            }
        }
        int count = 0;

        while(maxNum > 0){
            int count_1 = 0;
            int count_0 = 0;
            for(int i = 0; i < nums.size(); i++){
                if(nums[i] % 2){
                    count_1++;
                }
                else{
                    count_0++;
                }
                nums[i] >>= 1;
            }
            maxNum >>= 1;
            count += (count_1 * count_0);
        }

        return count;
    }
};