class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int sum = 0;
        for(int i = 0; i < k; i++){
            sum += cardPoints[i];
        }
        int maxVal = sum;
        k--;
        int j = cardPoints.size() - 1;

        while(k >= 0){
            sum += cardPoints[j--];
            sum -= cardPoints[k--];

            maxVal = max(maxVal, sum);
        }

        return maxVal;
    }
};