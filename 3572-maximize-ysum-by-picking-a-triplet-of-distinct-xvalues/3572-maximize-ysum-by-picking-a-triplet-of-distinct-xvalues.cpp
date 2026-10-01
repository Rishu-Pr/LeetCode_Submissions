class Solution {
public:
    int maxSumDistinctTriplet(vector<int>& x, vector<int>& y) {
        unordered_map<int, int> map;
        for(int i = 0; i < x.size(); i++){
            if(!map.count(x[i])){
                map[x[i]] = y[i];
            }
            else if(map.count(x[i]) && y[i] > map[x[i]]){
                map[x[i]] = y[i];
            }
        }

        vector<pair<int, int>> vec(map.begin(), map.end());

        sort(vec.begin(), vec.end(), [](const auto& a, const auto& b) {
            return a.second > b.second; 
        });
        if(vec.size() < 3){
            return -1;
        }

        int ans = 0;
        int cnt = 3;

        for (const auto& pair : vec) {
            if(cnt == 0){
                break;
            }
            ans += pair.second;
            cnt--;
        }

        return ans;
    }
};