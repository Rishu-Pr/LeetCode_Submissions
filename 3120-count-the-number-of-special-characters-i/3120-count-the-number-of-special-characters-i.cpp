class Solution {
public:
    int numberOfSpecialChars(string word) {
        vector<int> cap(26, 0);
        vector<int> small(26, 0);

        for(int i = 0; i < word.size(); i++){
            if(word[i] >= 'A' && word[i] <= 'Z') 
                cap[word[i] - 'A']++;
            else small[word[i] - 'a']++;
        }

        int count = 0;
        for(int i = 0; i < 26; i++)
            if(cap[i] && small[i]) count++;

        return count;
    }
};