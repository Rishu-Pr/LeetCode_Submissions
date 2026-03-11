class Solution {
public:
    int bitwiseComplement(int n)
    {
        int temp = n;
        int cnt = 0;
        while (temp > 0)
        {
            temp = temp >> 1;
            cnt++;
        }
        while (cnt > 0)
        {
            temp = temp << 1;
            temp = temp | 1;
            cnt--;
        }
        if (n == 0)
        {
            return 1;
        }
        return (temp & ~n);
    }
};