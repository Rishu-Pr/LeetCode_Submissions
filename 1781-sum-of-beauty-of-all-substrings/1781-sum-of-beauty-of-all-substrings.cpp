class Solution {
public:
    int beautySum(string s) {
        int cnt = 0;
        for(int i = 0; i < s.size(); i++){
            unordered_map<char, int> myMap;
            for(int j = i; j < s.size(); j++){
                myMap[s[j]]++;
                auto [minIt, maxIt] = minmax_element(myMap.begin(), myMap.end(), 
                    [](const auto& a, const auto& b) {
                    return a.second < b.second;
                });

                cnt += maxIt->second - minIt->second;
            }
        }

        return cnt;
    }
};