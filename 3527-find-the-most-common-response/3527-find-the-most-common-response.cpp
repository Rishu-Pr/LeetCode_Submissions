class Solution {
public:
    string findCommonResponse(vector<vector<string>>& responses) {
        unordered_map<string, int> map;
        
        for (const auto& row : responses) {
            unordered_set<string> seen(row.begin(), row.end());
            for (const string& s : seen) {
                map[s]++;
            }
        }

        string str;
        int freq = 0;
        for (const auto& [s, f] : map) {
            if (f > freq || (f == freq && s < str)) {
                freq = f;
                str = s;
            }
        }

        return str;
    }
};