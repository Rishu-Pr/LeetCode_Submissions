#define MOD 1000000007

class Solution {
public:
    int maximumXorProduct(long long a, long long b, int n) {
        long long A = (a >> n) << n;
        long long B = (b >> n) << n;

        n--;

        while(n + 1){
            long long bitA = (a >> n) & 1;
            long long bitB = (b >> n) & 1;

            if(bitA == bitB){
                A ^= (1LL << n);
                B ^= (1LL << n);
            }
            else{
                if(A < B){
                    A ^= (1LL << n);
                }
                else{
                    B ^= (1LL << n);
                }
            }
            n--;
        }

        return ((A % MOD) * (B % MOD)) % MOD;
    }
};