class Solution {
    bool isSorted(vector<int>& nums){
        for(int i=0; i < nums.size()-1; i++){
            if (nums[i] > nums[i+1]){
                return false;
            }
        }
        return true;
    }
public:
    int minimumPairRemoval(vector<int>& nums) {
        int ans = 0;
        while(!isSorted(nums)){
            int idx1 = nums.size()-2,idx2 = nums.size()-1;
            int minSum = nums[idx1] + nums[idx2];

            for(int i = nums.size()-2 ; i > 0 ; i--){
                if((nums[i-1] + nums[i]) <= minSum){
                    minSum = nums[i-1] + nums[i];
                    idx1 = i-1;
                    idx2 = i;
                }
            }

            nums[idx1] = minSum;
            nums.erase(nums.begin()+idx2);
            ans++;
        }
        return ans;
    }
};