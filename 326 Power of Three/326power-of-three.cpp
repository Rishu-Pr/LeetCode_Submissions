class Solution {
public:
    bool isPowerOfThree(int n)
    {
        bool ispow = true;
        if (n <= 0)
        {
            ispow = false;
        }

        while (n > 1)
        {
            if (n % 3 != 0)
            {
                ispow = false;
            }
            n /= 3;
        }
        return ispow;
    }
};