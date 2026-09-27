class Solution {
public:
    long long countCompleteDayPairs(vector<int>& hours) {
        vector<long long> V(24, 0);
        for(int i : hours){
            V[i % 24]++;
        }

        long long cnt = 0;
        cnt += V[0] * (V[0] - 1) / 2;
        cnt += V[12] * (V[12] - 1) / 2;

        for(int i = 1; i < 12; i++){
            cnt += V[i] * V[24 - i];
        }

        return cnt;
    }
};