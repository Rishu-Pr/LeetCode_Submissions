class Solution {
public:
    int binaryGap(int n){
        int max_Gap = 0;
        while (n){
            if (n % 2){
                if (n == 1) break;
                int cnt = 1;
                n >>= 1;

                while (n > 0 && n % 2 == 0){
                    cnt++;
                    n >>= 1;
                }
                max_Gap = (max_Gap < cnt) ? cnt : max_Gap;
            }
            else n >>= 1;
        }
        return max_Gap;
    }
};