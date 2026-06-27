class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        if (s.size() < p.size()) return {};
        vector<int> p_freq(26, 0);
        vector<int> window(26, 0);
        vector<int> ans;

        for(char chr : p){
            p_freq[chr - 'a']++;
        }

        for(int i = 0; i < p.size(); i++){
            window[s[i] - 'a']++;
        }

        int start = 0;
        int end = p.size() - 1;
        while(end < s.size() - 1){
            if(window == p_freq){
                ans.push_back(start);
            }
            window[s[start] - 'a']--;
            start++;
            end++;
            window[s[end] - 'a']++;

        }
        if(window == p_freq){
            ans.push_back(start);
        }

        return ans;
    }
};