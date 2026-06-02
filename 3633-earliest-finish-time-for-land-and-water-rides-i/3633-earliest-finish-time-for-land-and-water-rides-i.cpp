class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        vector<vector<int>> landFirst(landStartTime.size(), vector<int>(waterStartTime.size(), 0));
        vector<vector<int>> waterFirst(waterStartTime.size(), vector<int>(landStartTime.size(), 0));

        for(int i = 0; i < landStartTime.size(); i++){
            for(int j = 0; j < waterStartTime.size(); j++){
                landFirst[i][j] = landStartTime[i] + landDuration[i];
                if(landFirst[i][j] < waterStartTime[j]) landFirst[i][j] = waterStartTime[j] + waterDuration[j];
                else landFirst[i][j] += waterDuration[j];
            }
        }
        for(int i = 0; i < waterStartTime.size(); i++){
            for(int j = 0; j < landStartTime.size(); j++){
                waterFirst[i][j] =waterStartTime[i] + waterDuration[i];
                if(waterFirst[i][j] < landStartTime[j]) waterFirst[i][j] = landStartTime[j] + landDuration[j];
                else waterFirst[i][j] += landDuration[j];
            }
        }
        int minVal = landFirst[0][0];
        for(int i = 0; i < landFirst.size(); i++){
            for(int j = 0; j < landFirst[i].size(); j++){
                minVal = min(minVal, landFirst[i][j]);
            }
        }
        for(int i = 0; i < waterFirst.size(); i++){
            for(int j = 0; j < waterFirst[i].size(); j++){
                minVal = min(minVal, waterFirst[i][j]);
            }
        }

        return minVal;
    }
};