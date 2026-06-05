class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        vector<long long> V(n);
        V[0] = 1;
        vector<int> ptr(primes.size(), 0);

        int size = primes.size();
        vector<long long> next_multiple(size);
        for(int i = 0; i < size; i++) next_multiple[i] = primes[i];

        for (int idx = 1; idx < n; ++idx){
            long long minV = next_multiple[0];
            for(int i = 1; i < size; i++)
                minV = min(minV, next_multiple[i]);

            V[idx] = minV;
            for(int i = 0; i < size; i++)
                if(minV == next_multiple[i]){ 
                    ptr[i]++;
                    next_multiple[i] = V[ptr[i]] * primes[i];
                }
        }

        return V[n - 1];
    }
};