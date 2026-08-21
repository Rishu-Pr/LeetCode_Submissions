#include <vector>

#define MOD 1000000007

class Fancy { 
    vector<long long> V;
    long long multip = 1;
    long long adder = 0;

public:
    Fancy() {
        
    }

    long long power(long long b, long long e){
        long long res = 1;
        b %= MOD;
        while(e > 0){
            if(e % 2){
                res = (res * b) % MOD;
            }
            b = (b * b) % MOD;
            e /= 2;
        }

        return res;
    }
    
    void append(int val) {
        long long newAdder = ((val - adder) % MOD) + MOD;
        long long newMultip = power(multip, MOD - 2)% MOD;
        V.push_back(((newAdder % MOD) * newMultip) % MOD);
    }
    
    void addAll(int inc) {
        adder = (adder + inc) % MOD;
    }
    
    void multAll(int m) {
        multip = (multip * m) % MOD;
        adder = (adder * m) % MOD;
    }
    
    int getIndex(int idx) {
        if (idx >= V.size()) {
            return -1;
        }

        return (V[idx] * multip + adder) % MOD;
        
    }
};

/**
 * Your Fancy object will be instantiated and called as such:
 * Fancy* obj = new Fancy();
 * obj->append(val);
 * obj->addAll(inc);
 * obj->multAll(m);
 * int param_4 = obj->getIndex(idx);
 */