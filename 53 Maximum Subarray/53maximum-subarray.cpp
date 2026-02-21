class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max_Sum = INT_MIN,sum=0;
        for(int i=0;i < nums.size();i++){
            sum+=nums[i];

            if(sum>max_Sum) max_Sum = sum;
            if(sum<0) sum=0;
        }
        return max_Sum;
    }
};