class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> map1;
        for (int i = 0; i < nums.size(); i++) {
            map1[nums[i]]++;
        }

        vector<int> Ans;
        vector<pair<int, int>> vec(map1.begin(), map1.end());

        sort(vec.begin(), vec.end(),
             [](auto& a, auto& b) { return a.second < b.second; });

        for (int idx = vec.size() - k; idx < vec.size(); idx++) {
            Ans.push_back(vec[idx].first);
        }

        return Ans;
    }
};