class Solution {
public:
    string convert(string s, int numRows)
    {
        string s_Ans = "";
        vector<vector<char>> V(numRows);
        for (int i = 0; i < s.size();){

            for (int j = 0; j < numRows && i < s.size(); j++)
                V[j].push_back(s[i++]);

            for (int j = numRows - 2; j > 0 && i < s.size(); j--)
                V[j].push_back(s[i++]);

        }
        for (int i = 0; i < V.size(); i++){
            for (int j = 0; j < V[i].size(); j++)
                s_Ans.push_back(V[i][j]);

        }
        return s_Ans;
    }
};