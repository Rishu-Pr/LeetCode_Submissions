class Solution {
public:
    string largestNumber(vector<int> &nums)
    {
        vector<string> V(nums.size());
        string str = "";
        for (int i = 0; i < nums.size(); i++)
            V[i] = to_string(nums[i]);

        sort(V.begin(), V.end(), [](const string &a, const string &b)
             { return a + b > b + a; });

        for (int i = 0; i < V.size(); i++)
            str += V[i];

        if(str[0]=='0') return "0";
        return str;
    }
};