class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, int> map;
        int idx = 1;
        vector<vector<string>> V;

        for(int i = 0; i < strs.size(); i++){
            string sortedS = strs[i];
            sort(sortedS.begin(), sortedS.end());
            if(map.count(sortedS) == 0){
                map[sortedS] = idx++;
                V.push_back({strs[i]});
            }
            else{
                V[map[sortedS] - 1].push_back(strs[i]);
            }
        }

        return V;
    }
};