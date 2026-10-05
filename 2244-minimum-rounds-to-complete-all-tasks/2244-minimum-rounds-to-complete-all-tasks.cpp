class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        unordered_map<int, int> map;
        for(int i : tasks){
            map[i]++;
        }

        vector<pair<int, int>> Vec(map.begin(), map.end());
        // sort(Vec.begin(), Vec.end());
        int cnt = 0;

        for(int i = 0; i < Vec.size(); i++){
            if(Vec[i].second == 1){
                return -1;
            }
            else{
                cnt += (Vec[i].second + 2) / 3;
            }
        }

        return cnt;
    }
};