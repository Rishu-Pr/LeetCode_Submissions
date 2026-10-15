class Solution {
    bool isPalin(string& str){
        int s = 0;
        int e = str.size() - 1;
        while(s < e){
            if(str[s] != str[e]){
                return false;
            }
            s++;
            e--;
        }

        return true;
    }

    void solve(vector<vector<string>>& ans, vector<string>& temp, int idx, string& s){
        if(idx == s.size()){
            ans.push_back(temp);
            return;
        }

        for(int i = idx; i < s.size(); i++){
            string t = s.substr(idx, i - idx + 1);
            if(isPalin(t)){
                temp.push_back(t);
                solve(ans, temp, i + 1, s);
                temp.pop_back();
            }
        }
    }
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> temp;
        solve(ans, temp, 0, s);

        return ans;
    }
};