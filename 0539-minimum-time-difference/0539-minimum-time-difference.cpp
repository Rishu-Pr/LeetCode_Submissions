class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        sort(timePoints.begin(), timePoints.end());
        vector<int> minutes;
        for(int i = 0; i < timePoints.size(); i++){
            string hrs = timePoints[i].substr(0, 2);
            string min = timePoints[i].substr(3);

            int temp = (stoi(hrs) * 60) + stoi(min);
            minutes.push_back(temp);
        }

        int minV = minutes[1] - minutes[0];
        for(int i = 2; i < minutes.size(); i++){
            minV = min(minV, minutes[i] - minutes[i - 1]);
        }

        int temp = minutes.back() - minutes.front();
        minV = min(minV, 1440 - temp);

        return minV;
    }
};