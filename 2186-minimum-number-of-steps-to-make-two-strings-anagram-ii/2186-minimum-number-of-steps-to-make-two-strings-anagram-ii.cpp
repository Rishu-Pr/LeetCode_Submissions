class Solution {
public:
    int minSteps(string s, string t) {
        vector<int> sA(26, 0);
        for(char c : s){
            sA[c - 'a']++;
        }

        vector<int> tA(26, 0);
        for(char c : t){
            tA[c - 'a']++;
        }

        int cnt = 0;
        for(int i = 0; i < 26; i++){
            cnt += abs(tA[i] - sA[i]);
        }

        return cnt;
    }
};