class Solution {
public:
    int minSteps(string s, string t) {
        vector<int> tA(26, 0);
        for(char c : t){
            tA[c - 'a']++;
        }

        for(char c : s){
            if(tA[c - 'a'] > 0){
                tA[c - 'a']--;
            }
        }

        int cnt = 0;
        for(int i = 0; i < 26; i++){
            cnt += tA[i];
        }

        return cnt;
    }
};