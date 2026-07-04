class Solution {
public:
    int longestBeautifulSubstring(string word) {
        int m_len = 0;
        int count = 1;
        int vow = 1;

        for(int i = 1; i < word.size(); i++){
            if(word[i] == word[i - 1]){
                count++;
            }
            else if(word[i] > word[i - 1]){
                count++;
                vow++;
            }
            else{
                count = 1;
                vow = 1;
            }
            if(vow == 5){
                m_len = max(m_len, count);
            }
        }

        return m_len;
    }
};