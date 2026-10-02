class Solution {
public:
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        set<string> Set =  {" "};

        for(string s : words){
            set<string> temp;
            for(string str : Set){
                temp.insert(str + s);
            }
            Set.insert(temp.begin(), temp.end());
        }

        unordered_map<char, int> freq;
        for(char c : letters){
            freq[c]++;
        }

        int maxA = 0;
        for(string s : Set){
            int ans = 0;
            int i = 1;
            while(i < s.size() && freq.count(s[i]) && freq[s[i]] > 0){
                freq[s[i]]--;
                ans += score[s[i] - 'a'];
                i++;
            }
            if(i == s.size()){
                maxA = max(maxA, ans);
            }
            i--;
            while(i >= 1){
                freq[s[i]]++;
                i--;
            }
        }

        return maxA;
    }
};