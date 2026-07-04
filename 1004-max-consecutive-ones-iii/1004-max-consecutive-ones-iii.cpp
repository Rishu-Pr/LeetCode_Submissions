class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int leng = 0;
        int start = 0;

        int count_1 = 0;
        int count_0 = 0;
        for(int end = 0; end < nums.size(); end++){
            if(nums[end] == 1){
                count_1++;
            }
            else{
                count_0++;
            }

            while(count_0 > k){
                if(nums[start] == 1){
                    count_1--;
                }
                else{
                    count_0--;
                }
                start++;
            }

            leng = max(leng, end - start + 1);
        }

        return leng;
    }
};