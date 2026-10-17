class Solution {
public:
    string smallestPalindrome(string s) {
        vector<int> cnt(26, 0);
        for(char c : s){
            cnt[c - 'a']++;
        }

        string ans = "";
        char midC = '*';
        for(int i = 0; i < 26; i++){
            if(cnt[i] % 2){
                midC = i + 'a';
                cnt[i]--;
            }
            int V = cnt[i] / 2;
            while(V){
                ans += (i + 'a');
                cnt[i]--;
                V--;
            }
        }
        if(midC != '*'){
            ans += midC;
        }
        for(int i = 25; i >= 0; i--){
            while(cnt[i]){
                ans += (i + 'a');
                cnt[i]--;
            }
        }

        return ans;
    }
};