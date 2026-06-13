class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string str = "";
        for(int i = 0; i < words.size(); i++){
            int val = 0;
            for(int j = 0; j < words[i].size(); j++){
                val += weights[words[i][j] - 'a'];
            }
            val %= 26;
            str += 'a' + (25 - val);
        }

        return str;
    }
};