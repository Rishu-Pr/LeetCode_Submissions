class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        unordered_map<int, int> map;
        for(int x : nums){
            map[x]++;
        }
        vector<pair<int, int>> vec(map.begin(), map.end());
        sort(vec.begin(), vec.end(), [](const auto& a, const auto& b) {
            return a.first > b.first; 
        });

        if(k == nums.size()){
            return vec[0].first;
        }

        if(k == 1){
            for(const auto& pair : vec){
                if(pair.second == 1){
                    return pair.first;
                }
            }
        }
        else{
            int maxN = -1;
            if(map[nums.front()] == 1){
                maxN = max(maxN, nums[0]);
            }
            if(map[nums.back()] == 1){
                maxN = max(maxN, nums.back());
            }

            return maxN;
        }

        return -1;
    }
};