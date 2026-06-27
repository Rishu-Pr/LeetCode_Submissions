class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()){
            return false;
        }

        vector<int> freq(26, 0);
        for(char chr : s){
            freq[chr - 'a']++;
        }
        for(char chr : t){
            freq[chr - 'a']--;
        }

        for(int i = 0; i < freq.size(); i++){
            if(freq[i] != 0) return false;
        }

        return true;
    }
};