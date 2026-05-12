class Solution {
public:
    string removeKdigits(string num, int k) {
        if(num.size() == k) return "0";
        string ans = "";
        for (char c : num) {
            while (!ans.empty() && ans.back() > c && k > 0) {
                ans.pop_back();
                k--;
            }
            ans.push_back(c);
        }
        while(k && !ans.empty()){
            ans.pop_back();
            k--;
        }

        int i = 0;
        while(ans[i] == '0') i++;
        
        string substr_Ans = ans.substr(i);
        return substr_Ans.empty() ? "0" : substr_Ans;
    }
};