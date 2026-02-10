class Solution {
public:
    int countPrimes(int n) {
        vector<bool> V(n + 1, true);
        int cnt = 0;

        V[0] = V[1] = false;
        for (int i = 2; i < n; i++) {
            if (V[i]) {
                cnt++;
                for (int j = 2 * i; j < n; j = j+i) {
                    V[j] = 0;
                }
            }
        }
        return cnt;
    }
};