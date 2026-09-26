class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        unordered_map<string, int> uMap;
        string temp;
        s1 = s1 + " " + s2;
        for(char c : s1){
            if(c == ' '){
                uMap[temp]++;
                temp = "";
            }
            else{
                temp.push_back(c);
            }
        }
        uMap[temp]++;

        vector<string> cnt;
        for(const auto& [k, v] : uMap){
            if(v == 1){
                cnt.push_back(k);
            }
        }

        return cnt;
    }
};