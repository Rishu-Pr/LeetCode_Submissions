class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        unordered_map<int, int> map;
        for(int i = 0; i < nums.size(); i++){
            for(int j = i + 1; j < nums.size(); j++){
                map[nums[i] * nums[j]]++;
            }
        }

        int ans = 0;
        for(const auto& [v, f] : map){
            ans += f * (f - 1) * 4;
        }

        return ans;
    }
};