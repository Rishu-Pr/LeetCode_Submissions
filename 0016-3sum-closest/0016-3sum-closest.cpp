class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int ans = 1e9;
        int size = nums.size();

        for(int i = 0; i < size - 2; i++){
            int start = i + 1;
            int end = size - 1;

            while(start < end){
                int currentSum = nums[i] + nums[end] + nums[start];
                if(currentSum == target){
                    return currentSum;
                }
                if(abs(currentSum - target) < abs(ans - target)){
                    ans = currentSum;
                }
                if(currentSum < target){
                    start++;
                }
                else{
                    end--;
                }
            }
        }

        return ans;
    }
};