class Solution {
public:
    double myPow(double x, int n)
    {
        int isneg = (n < 0) ? 1 : 0;
        double ans = 1;
        if (isneg)
        {
            if (n == INT32_MIN)
            {
                ans = x;
                n = INT32_MAX;
            }
            else
                n = -n;
        }
        while (n > 0)
        {
            if (n % 2 == 0)
            {
                x *= x;
                n /= 2;
            }
            else
            {
                ans *= x;
                n--;
            }
        }
        if (isneg)
        {
            return (1 / ans);
        }

        return ans;
    }
};