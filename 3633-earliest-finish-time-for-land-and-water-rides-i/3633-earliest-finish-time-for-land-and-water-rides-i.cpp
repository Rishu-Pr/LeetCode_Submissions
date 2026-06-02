class Solution {
    int solve(vector<int>& FirstStartTime, vector<int>& FirstDuration, vector<int>& secondStartTime, vector<int>& secondDuration){
        int endRide1 = INT_MAX;
        for(int i = 0; i < FirstStartTime.size(); i++)
            endRide1 = min(endRide1, FirstStartTime[i] + FirstDuration[i]);

        int endRide2 = INT_MAX;
        for(int i = 0; i < secondStartTime.size(); i++)
            endRide2 = min(endRide2, max(secondStartTime[i], endRide1) + secondDuration[i]);

        return endRide2;
    }
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int landFirst = solve(landStartTime, landDuration, waterStartTime, waterDuration);
        int waterFirst = solve(waterStartTime, waterDuration, landStartTime, landDuration);

        return min(landFirst, waterFirst);
    }
};