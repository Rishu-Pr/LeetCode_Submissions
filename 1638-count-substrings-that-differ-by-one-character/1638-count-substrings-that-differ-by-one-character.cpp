class Solution {
public:
    int countSubstrings(string s, string t) {
        int cnt = 0;

        for(int i = 0; i < s.size(); i++){
            for(int j = 0; j < t.size(); j++){
                int m = 0;
                for(int k = 0; i + k < s.size() && j + k < t.size(); k++){
                    if (s[i + k] != t[j + k]){
                        m++;
                        if(m > 1) break;
                    }
                cnt += m;
                }
            }
        }
        return cnt;
    }
};