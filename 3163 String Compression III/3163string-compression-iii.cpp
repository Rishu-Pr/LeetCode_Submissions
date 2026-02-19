class Solution {
public:
    string compressedString(string word)
    {
        string s_Ans = "";
        for (int i = 0; i < word.size(); i++){
            char ch = word[i];
            int count = 1;

            while (i < word.size() - 1 && word[i] == word[i + 1]){
                if (count == 9){
                    s_Ans.push_back(count + '0');
                    s_Ans.push_back(ch);
                    count=0;
                };

                count++;
                i++;
            }
            s_Ans.push_back(count + '0');
            s_Ans.push_back(ch);
        }
        return s_Ans;
    }
};