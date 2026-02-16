class Solution {
public:
    int reverseBits(int n)
    {
        int ans = 0;
        for (int i = 0; i < 32; i++){
            int digit = (n % 2 == 0) ? 0 : 1;
            ans <<= 1;
            
            if (digit) ans += 1;

            n >>= 1;
        }
        return ans;
    }
};