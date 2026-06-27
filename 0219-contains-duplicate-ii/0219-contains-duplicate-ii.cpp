class Solution {
    static bool cmp(const pair<int, int>& a, const pair<int, int>& b) {
        if (a.first == b.first) {
            return a.second < b.second;
        }
        return a.first < b.first;
    }

public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        vector<pair<int, int>> map;
        for (int i = 0; i < nums.size(); i++) {
            map.push_back({nums[i], i});
        }

        sort(map.begin(), map.end(), cmp);

        int s = 0;
        int e = 1;
        
        while (e < map.size()) {
            if (map[s].first == map[e].first && (map[e].second - map[s].second) <= k) {
                return true;
            }
            
            s++;
            e++;
        }

        return false;
    }
};