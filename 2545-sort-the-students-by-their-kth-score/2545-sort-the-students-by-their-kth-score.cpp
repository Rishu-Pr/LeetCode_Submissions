class Solution {
public:
    vector<vector<int>> sortTheStudents(vector<vector<int>>& score, int k) {
        vector<vector<int>> V;
        vector<pair<int, int>> temp;
        for(int i = 0; i < score.size(); i++){
            temp.push_back({score[i][k], i});
        }
        sort(temp.begin(), temp.end(), [](const auto& a, const auto& b) {
            return a.first > b.first;
        });

        for(auto it : temp){
            V.push_back(score[it.second]);
        }

        return V;
    }
};