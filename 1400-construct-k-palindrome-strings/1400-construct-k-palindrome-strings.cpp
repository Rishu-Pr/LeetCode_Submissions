class Solution {
public:
    bool canConstruct(string s, int k) {
        if(s.size() < k){
            return false;
        }
        vector<int> cnt(26, 0);
        for(char c : s){
            cnt[c - 'a']++;
        }

        int odd = 0;
        for(int i : cnt){
            if(i % 2){
                odd++;
            }
        }

        return (odd <= k);
    }
};