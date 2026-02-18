class Solution {
public:
    bool hasAlternatingBits(int n)
    {
        int lstDigit = -1;
        while (n > 0)
        {
            if (lstDigit == n % 2) return false;

            lstDigit = n % 2;
            n >>= 1;
        }
        return true;
    }
};