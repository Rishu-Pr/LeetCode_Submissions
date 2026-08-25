class Solution {
public:
    long long calculateScore(string s) {
        unordered_map<char, set<int>> map;
        long long score = 0;

        for(int i = 0; i < s.size(); i++){
            char compli = (25 - (s[i] - 'a')) + 'a';
            if(map.count(compli) && !map[compli].empty()){
                int j = *(map[compli].rbegin());
                score += (i - j);
                map[compli].erase(j);
            }
            else{
                map[s[i]].insert(i);
            }
        }

        return score;
    }
};