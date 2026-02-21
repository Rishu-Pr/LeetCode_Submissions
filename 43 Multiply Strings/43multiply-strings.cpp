class Solution
{
public:
    vector<int> convertArr(string s)
    {
        vector<int> V_ans;
        for (auto c : s)
            V_ans.push_back(c - '0');

        return V_ans;
    }

    string multiply(string num1, string num2)
    {
        if (num1 == "0" || num2 == "0") return "0";
        string str_Ans = "";
        vector<int> a = convertArr(num1);
        vector<int> b = convertArr(num2);
        vector<int> ans(a.size(), 0);
        int unitplace = 0;

        for (int i = 0; i < b.size(); i++){
            for (int j = 0; j < a.size(); j++){
                if (j + unitplace > ans.size() - 1){
                    ans.resize(ans.size() + 1);
                    ans[ans.size() - 1] = 0;
                }
                ans[j + unitplace] += b[i] * a[j];
            }
            unitplace++;
        }

        for (int k = ans.size() - 1; k > 0; k--){
            ans[k - 1] += ans[k] / 10;
            ans[k] %= 10;
        }

        while (ans[0] > 9){
            int carry = ans[0] / 10;
            ans[0] %= 10;
            ans.insert(ans.begin(), carry);
        }

        for (int i = 0; i < ans.size(); i++)
            str_Ans.push_back(ans[i] + '0');

        return str_Ans;
    }
};