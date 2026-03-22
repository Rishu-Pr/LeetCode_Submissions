class Solution{
private:
    void getAns(string &s, vector<string> &Ans, int index, string &output){
        if (index >= s.size()){
            Ans.push_back(output);
            return;
        }

        output.push_back(s[index]);
        getAns(s, Ans, index + 1, output);
        output.pop_back();

        if (!(s[index] >= '0' && s[index] <= '9')){

            if (s[index] >= 'A' && s[index] <= 'Z') s[index] += 32;
            else if (s[index] >= 'a' && s[index] <= 'z') s[index] -= 32;

            output.push_back(s[index]);
            getAns(s, Ans, index + 1, output);
            output.pop_back();
        }
    }

public:
    vector<string> letterCasePermutation(string s)
    {
        vector<string> Ans;
        string output = "";
        getAns(s, Ans, 0, output);
        return Ans;
    }
};