class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        int cnt = 0;
        sort(nums.begin(), nums.end());
        
        int i = 0;
        int j = 1;
        while(j != nums.size()){
            if (i == j) {
                j++;
                continue;
            }
            int val = abs(nums[j] - nums[i]);
            if(val == k){
                cnt++;
                do {
                    j++;
                } while (j != nums.size() && nums[j] == nums[j - 1]); 
            }
            else if(val > k){
                i++;
            }
            else{
                j++;
            }
        }

        return cnt;
    }
};