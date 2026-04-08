class Solution {
public:
    string resultingString(string s) {
        string ans = "";

        for(int i = 0; i < s.size(); i++){
            if(ans.empty()) ans.push_back(s[i]);

            else if( abs(ans.back()-s[i]) == 1 || abs(ans.back()-s[i]) == 25){
                ans.pop_back();
            }

            else ans.push_back(s[i]);
        }

        return ans;
    }
};