class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        for(int i = 1; i < n; i++){
            nums[i] += nums[i - 1];
        }
        unordered_map<int, int> map;
        map[0] = 1;

        int cnt = 0;
        for(int x : nums){
            if(map.count(x - k)){
                cnt += map[x - k];
            }
            map[x]++;
        }

        return cnt;
    }
};