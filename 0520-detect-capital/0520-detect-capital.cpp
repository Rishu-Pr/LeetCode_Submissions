class Solution {
public:
    bool detectCapitalUse(string word) {
        if(word.size() < 1) return true;

        int cap = 0;
        int small = 0;

        for(int i = 0; i < word.size(); i++){
            if(word[i] >= 'A' && word[i] <= 'Z') cap++;
            else small++;
        }

        if(!cap || !small) return true;
        else if(cap == 1 && (word[0] >= 'A' && word[0] <= 'Z') ) return true;
        else return false;
    }
};