class Solution {
    void solve(string& s, vector<string>& ans, int idx, int bal, string& temp){
        if(bal < 0){
            return;
        }
        if(idx == s.size()){
            if(bal == 0){
                ans.push_back(temp);
            }
            return;
        }
        
        // Don't take
        solve(s, ans, idx + 1, bal, temp);

        // Take
        if(s[idx] == '('){
            temp.push_back(s[idx]);
            solve(s, ans, idx + 1, bal + 1, temp);
            temp.pop_back();
        }
        else if(s[idx] == ')'){
            temp.push_back(s[idx]);
            solve(s, ans, idx + 1, bal - 1, temp);
            temp.pop_back();
        }
        else{
            temp.push_back(s[idx]);
            solve(s, ans, idx + 1, bal, temp);
            temp.pop_back();
        }
    }
public:
    vector<string> removeInvalidParentheses(string s) {
        vector<string> ans;
        string temp = "";
        solve(s, ans, 0, 0, temp);
        
        // sort(ans.begin(), ans.end());
        // vector<string> need;

        // need.push_back(ans.back());
        // for(int i = ans.size() - 2; i >= 0; i--){
        //     if(ans[i + 1].size() == ans[i].size()){
        //         need.push_back(ans[i]);
        //     }
        // }
        // sort(ans.begin(), ans.end(), [](const string& a, const string& b) {
        //     return a.size() > b.size();
        // });

        int size = ans.front().size();
        for(int i = 1; i < ans.size(); i++){
            if(ans[i].size() > size){
                size = ans[i].size();
            }
        }
        vector<string> need;

        for(int i = 0; i < ans.size(); i++){
            if(ans[i].size() == size){
                need.push_back(ans[i]);
            }
            // else{
            //     break;
            // }
        }
        
        sort(need.begin(), need.end());

        auto new_end = unique(need.begin(), need.end());
        need.erase(new_end, need.end());

        return need;

    }
};