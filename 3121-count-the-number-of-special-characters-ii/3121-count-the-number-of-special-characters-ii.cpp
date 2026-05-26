class Solution {
public:
    int numberOfSpecialChars(string word) {
        unordered_map<char, int> map;
        for(int i = 0; i < word.size(); i++)
            if(word[i] >= 'A' && word[i] <= 'Z')
                if(map.find(word[i]) == map.end()) map[word[i]] = i;

        if(map.empty()) return 0;

        vector<int> ans(26, 0);
        for(int i = 0; i < word.size(); i++){
            if(word[i] >= 'a' && word[i] <= 'z'){
                int charIndex = word[i] - 'a';
                char upperChar = toupper(word[i]);
                
                if(ans[charIndex] == -1) continue;
                
                if(map.count(upperChar) && i > map[upperChar]) ans[charIndex] = -1;
                else ans[charIndex]++;
                
            }
        }

        int sum = 0;
        for(int i = 0; i < 26; i++)
            if(ans[i] > 0 && map[i + 'A']) sum++;
        
        return sum;
    }
};