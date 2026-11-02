class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        unordered_map<string, int> map;
        for(string s : dictionary){
            map[s]++;
        }

        istringstream iss(sentence);
        string word;
        vector<string> words;

        while (iss >> word) {
            words.push_back(word);
        }

        for(int i = 0; i < words.size(); i++){
            string s = words[i];
            string temp = "";
            for(char c : s){
                temp += c;
                if(map.count(temp)){
                    words[i] = temp;
                    break;
                }
            }
        }

        string ans = "";
        for(string s : words){
            ans += s;
            ans += ' ';
        }
        ans.pop_back();

        return ans;
    }
};