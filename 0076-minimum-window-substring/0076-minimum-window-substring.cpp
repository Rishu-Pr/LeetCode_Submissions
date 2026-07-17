class Solution {
public:
    string minWindow(string s, string t) {
        if(t == "") return "";
        unordered_map<char, int> map_S;
        unordered_map<char, int> map_T;

        for(char chr : t){
            map_T[chr]++;
        }

        int have = 0;
        int need = map_T.size();
        int strt = 0;
        int len = 1e9;

        int start_ans = 0;

        for(int i = 0; i < s.size(); i++){
            int chr = s[i];
            map_S[chr]++;

            if(map_T.count(chr) && map_S[chr] == map_T[chr]){
                have++;
            }

            while(have == need){
                if((i - strt + 1) < len){
                    start_ans = strt;
                    len = min(len, i - strt + 1);
                }
                map_S[s[strt]]--;

                if(map_T.count(s[strt]) && map_S[s[strt]] < map_T[s[strt]]){
                    have--;
                }
  
                strt++;
            }
        }

        if(len == 1e9) return "";
        return s.substr(start_ans, len);
    }
};