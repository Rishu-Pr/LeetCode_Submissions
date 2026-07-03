class Solution{
public:
    vector<string> findRepeatedDnaSequences(string s){
        if (s.size() < 10)
            return {};
        unordered_map<string, int> map1;
        vector<string> ans;

        int idx_s = 0;

        while (idx_s + 9 < s.size())
        {
            string str = s.substr(idx_s, 10);
            map1[str]++;

            if(map1[str] ==2){
                ans.push_back(str);
            }

            idx_s++;
        }

        return ans;
    }
};