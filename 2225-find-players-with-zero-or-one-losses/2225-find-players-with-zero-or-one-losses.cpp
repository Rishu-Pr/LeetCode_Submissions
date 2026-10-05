class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        unordered_map<int, int> loss;
        for(int i = 0; i < matches.size(); i++){
            loss[matches[i][0]] = 0;
            loss[matches[i][1]] = 0;
        }
        for(int i = 0; i < matches.size(); i++){
            loss[matches[i][1]]++;
        }

        vector<int> loss0;
        vector<int> loss1;

        for(const auto& [d,f] : loss){
            if(f == 0){
                loss0.push_back(d);
            }
            else if(f == 1){
                loss1.push_back(d);
            }
        }
        sort(loss0.begin(), loss0.end());
        sort(loss1.begin(), loss1.end());

        return {loss0, loss1};
    }
};