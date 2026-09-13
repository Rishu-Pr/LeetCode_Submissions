class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string,int> map1;
        for(int i = 0 ;i < words.size() ;i++) map1[words[i]]++;

        vector<string> ans;
        vector<pair<string,int>> vec(map1.begin(),map1.end());

        sort(vec.begin(),vec.end(),[](auto& a, auto& b) {
            if(a.second == b.second){
                return a.first < b.first;
            } 
            return a.second > b.second; 
        });

        for(int i = 0 ;i < k ;i++){ 
            ans.push_back(vec[i].first);
        }
        return ans;
    }
};