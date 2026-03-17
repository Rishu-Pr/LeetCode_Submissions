class Solution {
public:
    vector<vector<int>> findPrimePairs(int n) {
        vector<int> V(n + 1, 0);

        for (int i = 2; i <= n; i++) {
            V[i] = i;
        }

        for (int i = 2; i * i <= n; i++) {
            if (V[i] != -1) {
                for (int j = i * i; j <= n; j += i) {
                    V[j] = -1;
                }
            }
        }
        vector<int> primes;
        for (int i = 2; i <= n; i++) {
            if (V[i] != -1)
                primes.push_back(i);
        }

        vector<vector<int>> V_Ans;

        int start = 0;
        int end = primes.size() - 1;
        while (start <= end) {
            if (primes[start] + primes[end] == n)
                V_Ans.push_back({primes[start++], primes[end--]});
            else if (primes[start] + primes[end] > n)
                end--;
            else
                start++;
        }

        return V_Ans;
    }
};