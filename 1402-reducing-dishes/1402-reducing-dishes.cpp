class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        int n = satisfaction.size();

        int maxVal = INT_MIN;
        sort(satisfaction.begin(), satisfaction.end());

        for(int i = 0; i < n; i++){
            int idx = 1;
            int sum = 0;
            for(int j = i; j < n; j++){
                sum += satisfaction[j] * idx;
                idx++;
            }
            maxVal = max(maxVal, sum);
        }
        
        return (maxVal <= 0) ? 0 : maxVal;
    }
};