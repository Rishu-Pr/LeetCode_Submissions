class Solution {
public:
    string frequencySort(string s)
    {
        string str = "";
        map<char, int> my_map;
        for (auto ch : s)
            my_map[ch]++;

        vector<pair<char, int>>
            vec(my_map.begin(), my_map.end());

        sort(vec.begin(), vec.end(), [](auto &a, auto &b)
             { return a.second < b.second; });

        for (auto &p : vec)
            str.append(p.second, p.first);
        reverse(str.begin(), str.end());
        return str;
    }
};