class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.size() > s2.size()) return false;

        vector<int> s1_freq(26, 0);
        vector<int> window(26, 0);
        for(char chr : s1){
            s1_freq[chr - 'a']++;
        }
        for(int i = 0; i < s1.size(); i++){
            window[s2[i] - 'a']++;
        }

        int s = 0;
        int e = s1.size() - 1;
        while(e < s2.size() - 1){
            if(s1_freq == window) return true;
            
            window[s2[s] - 'a']--;
            s++;
            e++;
            window[s2[e] - 'a']++;
        }
        if(s1_freq == window) return true;

        return false;
    }
};