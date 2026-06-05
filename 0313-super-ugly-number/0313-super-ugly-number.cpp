class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        vector<long long> V = {1};
        vector<long long> ptr(primes.size(), 0);

        while(V.size() < n){
            long long minV = INT_MAX;
            for(int i = 0; i < ptr.size(); i++)
                minV = min(minV, V[ptr[i]] * primes[i]);

            V.push_back(minV);
            for(int i = 0; i < ptr.size(); i++)
                if(minV == V[ptr[i]] * primes[i]) ptr[i]++;
        }

        return V.back();
    }
};