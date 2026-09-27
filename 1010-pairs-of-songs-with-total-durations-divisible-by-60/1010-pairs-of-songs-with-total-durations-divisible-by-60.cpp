class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        vector<long long> V(60, 0);
        for(int i : time){
            V[i % 60]++;
        }

        int cnt = 0;
        
        cnt += V[0] * (V[0] - 1) / 2;
        cnt += V[30] * (V[30] - 1) / 2;

        for(int i = 1; i < 30; i++){
            cnt += V[i] * V[60 - i];
        }

        return cnt;
    }
};