class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        int ans = 0;
        for(int i = 0; i < patterns.size(); i++){
            string s_curr = patterns[i];
            if(word.find(s_curr) != string::npos){
                ans++;
            }
        }

        return ans;
    }
};