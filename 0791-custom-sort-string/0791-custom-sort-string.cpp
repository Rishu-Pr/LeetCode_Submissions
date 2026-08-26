class Solution {
public:
    string customSortString(string order, string s) {
        unordered_map<char, int> map;
        for(int i = 0; i < s.size(); i++){
            map[s[i]]++;
        }
        string ans = "";
        for(char chr : order){
            for(int i = map[chr]; i > 0; i--){
                ans += chr;
            }
            map.erase(chr);
        }
        for(auto it : map){
            for(int i = it.second; i > 0; i--){
                ans += it.first;
            }
        }

        return ans;
    }
};