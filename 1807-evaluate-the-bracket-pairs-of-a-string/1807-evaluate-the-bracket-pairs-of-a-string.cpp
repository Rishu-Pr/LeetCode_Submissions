class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string, string> map;
        for(vector<string> V : knowledge){
            map[V[0]] = V[1];
        }
        string ans = "";
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '('){
                i++;
                string word = "";
                while(s[i] != ')'){
                    word += s[i];
                    i++;
                }

                if(map.count(word)){
                    ans += map[word];
                }
                else{
                    ans += "?";
                }
                // i++;
            }
            else{
                ans += s[i];
            }
        }

        return ans;
    }
};