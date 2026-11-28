class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n = nums.size();
        int cnt = 0;
        int sum = 0;

        unordered_map<int, int> map;
        map[0]++;
        for(int x : nums){
            sum += x;
            int rem = sum % k;

            if(rem < 0){
                rem += k;
            }

            if(map.count(rem)){
                cnt += map[rem];
            }

            map[rem]++;
        }

        return cnt;
    }
};