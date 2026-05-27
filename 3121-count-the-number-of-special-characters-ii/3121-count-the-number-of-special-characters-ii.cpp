class Solution {
public:
    int numberOfSpecialChars(string word) {
        vector<int> vec(26, -1);
        for(int i = 0; i < word.size(); i++){
            if(word[i] >= 'A' && word[i] <='Z')
                if(vec[word[i] - 'A'] == -1) vec[word[i] - 'A'] = i;
        }

        vector<int> ans(26, -1);
        for(int i = 0; i < word.size(); i++){
            if (word[i] >= 'a' && word[i] <= 'z') {
                ans[word[i] - 'a'] = i;
            }
        }

        int sum = 0;
        for(int i = 0; i < 26; i++)
            if(ans[i] != -1 && vec[i] != -1 && ans[i] < vec[i]) sum++;
        
        return sum;
    }
};